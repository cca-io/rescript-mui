import CustomProps from './../custom-props';

const defaults = {
	key: {
		type: {
			name: 'string',
		},
		required: false,
		description: '-',
	},
	ref: {
		type: {
			name: 'custom',
			reasonType: 'React.Ref.t(option(Dom.element))',
			jsType: 'React.Ref.t(option(Dom.element))',
		},
		required: false,
		description: '-',
	},
};

const GetCustomProps = (componentName: string) =>
	typeof CustomProps[componentName] !== 'undefined'
		? {
				...CustomProps[componentName],
				...defaults,
			}
		: defaults;

export default GetCustomProps;
