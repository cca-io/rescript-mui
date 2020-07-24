module.exports = {
  title: 'BS-Material-UI',
  tagline: 'Material UI Bindings for ReasonML',
  url: 'https://jsiebern.github.io/bs-material-ui/',
  baseUrl: '/',
  favicon: 'img/favicon.png',
  organizationName: 'jsiebern', // Usually your GitHub org/user name.
  projectName: 'bs-material-ui', // Usually your repo name.
  themeConfig: {
    hideOnScroll: true,
    prism: {
      theme: require('prism-react-renderer/themes/github'),
      darkTheme: require('prism-react-renderer/themes/oceanicNext'),
    },
    navbar: {
      title: 'BS Material UI',
      logo: {
        alt: 'BS Material UI Logo',
        src: 'img/logo.svg',
        srcDark: 'img/logo.svg',
      },
      links: [
        { to: 'docs/introduction', label: 'Docs', position: 'left' },
        { to: 'docs/changelog', label: 'Changelog', position: 'left' },
        {
          href: 'https://material-ui.com/versions/#latest-versions',
          label: 'Currently on MUI version: v4.11.0',
          position: 'right',
        },
        {
          href: 'https://github.com/jsiebern/bs-material-ui',
          label: 'GitHub',
          position: 'right',
        },
      ],
    },
    footer: {
      style: 'dark',
      links: [
        {
          title: 'Docs',
          items: [
            {
              label: 'Docs',
              to: 'docs/introduction',
            },
          ],
        },
      ],
    },
  },
  presets: [
    [
      '@docusaurus/preset-classic',
      {
        docs: {
          sidebarPath: require.resolve('./sidebars.js'),
          admonitions: {
            // infima: false,
          },
        },
        theme: {
          customCss: require.resolve('./src/css/custom.css'),
        },
      },
    ],
  ],
};
