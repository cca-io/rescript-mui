import * as Fs from 'fs';
import * as Path from 'path';
import * as rimraf from 'rimraf';

import outputDirectory from './output';

export default (muiSrc: muiSrc) => {
  if (Fs.existsSync(Path.join(outputDirectory, 'rescript', muiSrc))) {
    rimraf.sync(Path.join(outputDirectory, 'rescript', muiSrc));
  }
  const requiredFolders = ['rescript', Path.join('rescript', muiSrc)];
  requiredFolders.forEach((folder) => {
    const path = Path.join(outputDirectory, folder);
    if (!Fs.existsSync(path)) {
      Fs.mkdirSync(path);
    }
  });
};
