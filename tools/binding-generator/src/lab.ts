import * as Fs from 'fs';
import * as Path from 'path';

import outputDirectory from './output';
import ParseComponents from './parse-components';
import PrepareOutput from './prepare-output';

const muiSrc: muiSrc = 'lab';

const parseInit = () => {
  const components = ParseComponents(muiSrc);

  // Write component files
  components.forEach(({ name, src }) => {
    Fs.writeFileSync(
      Path.join(outputDirectory, 'rescript', muiSrc, `MaterialUi_${name}.res`),
      src,
    );
  });

  Fs.writeFileSync(
    Path.join(outputDirectory, 'rescript', muiSrc, 'MaterialUi_Lab.res'),
    components
      .map((component) =>
        component != null
          ? `module ${component.name} = MaterialUi_${component.name};`
          : '',
      )
      .join('\n'),
  );
};

PrepareOutput(muiSrc);
parseInit();
