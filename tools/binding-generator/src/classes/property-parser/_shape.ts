import Base from './base';
import ResolveArgument from './resolve-argument';
import GenerateReasonName from '../../helpers/generate-reason-name';
import { upperFirst } from 'lodash';
import { generateAny } from './helpers';

const factory = (propertyType: PropType$Shape) => {
	return class ShapeParser extends Base {
		private _propertyType: PropType$Shape = propertyType;
		private _moduleName = upperFirst(
			this.property.safeName.startsWith('_') ? this.property.safeName.substr(1) : this.property.safeName,
		);

		public executeParse() {
			const shapeArgs = this.resolveShape();
			if (shapeArgs.length) {
				this._module = `
                    module ${this._moduleName} {
                        [@bs.deriving abstract]
                        type t = {
                            ${shapeArgs
								.map(
									(arg) => `
                                ${!arg.required ? '[@bs.optional]' : ''}
                                ${arg.key !== arg.keySafe ? `[@bs.as "${arg.key}"]` : ''}
                                ${arg.keySafe}: ${arg.type}
                            `,
								)
								.join(',')}
                        };
                        let make = t;

                        let unwrap = (obj: ${this.property.signature.required ? 't' : 'option(t)'}) => {
                            ${this.property.signature.required
								? `
                                let unwrappedMap = Js.Dict.empty();
                                ${shapeArgs
									.map(
										(arg) =>
											arg.required
												? `
                                    unwrappedMap
                                        |. Js.Dict.set(
                                            "${arg.key}",
                                            ${arg.wrapJs(`obj |. ${arg.keySafe}Get`)}
                                            |. MaterialUi_Helpers.toJsUnsafe
                                        );
                                `
												: `
                                    switch (${arg.wrapJs(`obj |. ${arg.keySafe}Get`)}) {
                                        | Some(v) =>
                                            unwrappedMap
                                                |. Js.Dict.set(
                                                    "${arg.key}",
                                                    v
                                                    |. MaterialUi_Helpers.toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                `,
									)
									.join('')}
                                unwrappedMap;
                            `
								: `
                                switch (obj) {
                                    | Some(obj) =>
                                        let unwrappedMap = Js.Dict.empty();
                                        ${shapeArgs
											.map(
												(arg) =>
													arg.required
														? `
                                            unwrappedMap
                                                |. Js.Dict.set(
                                                    "${arg.key}",
                                                    ${arg.wrapJs(`obj |. ${arg.keySafe}Get`)}
                                                    |. MaterialUi_Helpers.toJsUnsafe
                                                );
                                        `
														: `
                                            switch (${arg.wrapJs(`obj |. ${arg.keySafe}Get`)}) {
                                                | Some(v) =>
                                                    unwrappedMap
                                                        |. Js.Dict.set(
                                                            "${arg.key}",
                                                            v
                                                            |. MaterialUi_Helpers.toJsUnsafe
                                                        );
                                                | None => ()    
                                            };
                                        `,
											)
											.join('')}
                                        Some(unwrappedMap);
                                    | None => None
                                };
                            `}
                            
                        };
                    };
                `;

				this._wrapJs = (name) => `${this._moduleName}.unwrap(${name})`;
				this._reasonType = `${this._moduleName}.t`;
				this._jsType = generateAny();
			} else {
				this._valid = false;
			}
		}

		private resolveShape() {
			const shapes: {
				key: string;
				keySafe: string;
				type: string;
				wrapJs: (k: string) => string;
				jsType: string;
				required: boolean;
			}[] = [];

			Object.keys(this._propertyType.value).forEach((key) => {
				const type = this._propertyType.value[key];
				const argumentParser = ResolveArgument(key, type.required, type, this._property);
				if (argumentParser && argumentParser.valid) {
					shapes.push({
						key,
						keySafe: GenerateReasonName(key, false),
						type: argumentParser.reasonType,
						wrapJs: argumentParser.wrapJs,
						jsType: argumentParser.jsType,
						required: type.required,
					});
				}
			});

			return shapes;
		}
	};
};

export default factory;
