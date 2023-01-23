const bpmr = require('babel-plugin-module-resolver');
const fse = require('fs-extra');
const path = require('path');

const errorCodesPath = path.resolve(
  __dirname,
  './public/static/error-codes.json',
);

function resolvePath(sourcePath, currentFile, opts) {
  if (sourcePath === 'markdown') {
    const base = currentFile.substring(__dirname.length).slice(0, -3);
    return `${__dirname}/docs/src/${base}/`;
  }

  return bpmr.resolvePath(sourcePath, currentFile, opts);
}

const alias = {
  '@mui/core': './core',
  '@mui/material': './material',
  '@mui/lab': './lab',
  '@mui/base': './base',
  '@mui/styles': './styles',
  '@mui/styled-engine': './styled-engine',
  '@mui/private-theming': './private-theming',
  '@mui/system': './system',
  '@mui/utils': './utils',
  '@mui/utils/macros/MuiError.macro': './utils/macros/MuiError.macro',
  '../generateUtilityClass': './utils/generateUtilityClass',
  docs: './',
  modules: '../modules',
  pages: './pages',
};

const { version: transformRuntimeVersion } = fse.readJSONSync(
  require.resolve('@babel/runtime-corejs2/package.json'),
);

module.exports = {
  presets: [
    // backport of https://github.com/zeit/next.js/pull/9511
    [
      'next/babel',
      { 'transform-runtime': { corejs: 2, version: transformRuntimeVersion } },
    ],
    '@babel/preset-typescript',
  ],
  plugins: [
    // [
    //   'babel-plugin-macros',
    //   {
    //     // muiError: {
    //     //   errorCodesPath,
    //     // },
    //   },
    // ],
    'babel-plugin-optimize-clsx',
    // for IE 11 support
    '@babel/plugin-transform-object-assign',
    'babel-plugin-preval',
    [
      'babel-plugin-module-resolver',
      {
        alias,
        transformFunctions: ['require', 'require.context'],
        resolvePath,
      },
    ],
  ],
  ignore: [/@babel[\\|/]runtime/], // Fix a Windows issue.
  env: {
    production: {
      plugins: [
        '@babel/plugin-transform-react-constant-elements',
        'babel-plugin-transform-dev-warning',
        [
          'babel-plugin-react-remove-properties',
          { properties: ['data-mui-test'] },
        ],
        ['babel-plugin-transform-react-remove-prop-types', { mode: 'remove' }],
      ],
    },
  },
};
