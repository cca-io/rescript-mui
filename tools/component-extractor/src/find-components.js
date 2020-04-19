const fs = require('fs');
const path = require('path');

const componentRegex = /^([A-Z][a-z]+)+\.js/;

// Returns the component source in a flat array.
export default function findComponents(
  directory = `./core`,
  components = [],
  level = 0,
) {
  const items = fs.readdirSync(directory);
  if (level > 1) {
    // return;
  }

  items.forEach((item) => {
    const itemPath = path.resolve(directory, item);

    if (fs.statSync(itemPath).isDirectory()) {
      findComponents(itemPath, components, level + 1);
      return;
    }

    if (!componentRegex.test(item)) {
      return;
    }

    components.push(itemPath);
  });

  return components;
}
