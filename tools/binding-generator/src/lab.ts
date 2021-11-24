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
      Path.join(outputDirectory, 'rescript', muiSrc, `${name}.res`),
      src.replace(/(\W*)(Number|Any)\./g, '$1MaterialUi.$2.'),
    );
  });
};

PrepareOutput(muiSrc);
parseInit();
