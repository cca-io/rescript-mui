import kebabCase from 'lodash/kebabCase';

const inheritedComponentRegexp = /\/\/ @inheritedComponent (.*)/;

export default function getInheritance(testInfo, src) {
	let inheritedComponentName = testInfo.inheritComponent;

	if (inheritedComponentName == null) {
		const match = src.match(inheritedComponentRegexp);
		if (match !== null) {
			inheritedComponentName = match[1];
		}
	}

	if (inheritedComponentName == null) {
		return null;
	}

	let pathname;

	switch (inheritedComponentName) {
		case 'Transition':
			pathname = 'https://reactcommunity.org/react-transition-group/#Transition';
			break;

		default:
			pathname = `/api/${kebabCase(inheritedComponentName)}`;
			break;
	}

	return {
		component: inheritedComponentName,
		pathname,
	};
}
