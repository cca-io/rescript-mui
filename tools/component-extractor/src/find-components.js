const fs = require('fs');
const path = require('path');

const componentRegex = /^([A-Z][a-z]+)+\.js/;

// Returns the component source in a flat array.
// function findComponents(directory = path.resolve(__dirname, '../../../../src'), components = []) {
export default function findComponents(directory = `./core`, components = []) {
  const items = fs.readdirSync(directory);

  items.forEach((item) => {
    const itemPath = path.resolve(directory, item);

    if (fs.statSync(itemPath).isDirectory()) {
      findComponents(itemPath, components);
      return;
    }

    if (!componentRegex.test(item)) {
      return;
    }

    components.push(itemPath);
  });

  return components;
}
