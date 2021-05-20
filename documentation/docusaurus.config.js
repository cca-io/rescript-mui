module.exports = {
  title: 'ReScript-Material-UI',
  tagline: 'Material-UI Bindings for ReScript',
  url: 'https://cca-io.github.io/rescript-material-ui',
  baseUrl: '/rescript-material-ui/',
  favicon: 'img/favicon.png',
  organizationName: 'cca-io', // Usually your GitHub org/user name.
  projectName: 'rescript-material-ui', // Usually your repo name.
  themeConfig: {
    hideOnScroll: true,
    colorMode: {
      defaultMode: 'light',
    },
    prism: {
      theme: require('prism-react-renderer/themes/github'),
      darkTheme: require('prism-react-renderer/themes/oceanicNext'),
    },
    navbar: {
      title: 'ReScript Material-UI',
      logo: {
        alt: 'ReScript Material-UI Logo',
        src: 'img/logo.svg',
        srcDark: 'img/logo-inv.svg',
      },
      items: [
        { to: 'docs/introduction', label: 'Docs', position: 'left' },
        { to: 'docs/changelog', label: 'Changelog', position: 'left' },
        { to: 'docs/examples', label: 'Examples', position: 'left' },
        {
          href: 'https://material-ui.com/versions/#stable-versions',
          label: 'Currently on MUI version: v4.11.3',
          position: 'right',
        },
        { to: 'docs/contributing', label: 'Contributing', position: 'right' },
        {
          href: 'https://github.com/cca-io/rescript-material-ui',
          label: 'GitHub',
          position: 'right',
        },
      ],
    },
    footer: {
      style: 'dark',
      links: [
        {
          title: ' ',
          items: [
            {
              label: 'Privacy Policy',
              to: 'docs/legal/privacy',
            },
          ],
        },
        {
          title: ' ',
          items: [
            {
              label: 'Legal Notice',
              to: 'docs/legal/notice',
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
