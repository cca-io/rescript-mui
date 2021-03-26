module.exports = {
  title: 'BS-Material-UI',
  tagline: 'Material UI Bindings for ReasonML',
  url: 'https://jsiebern.github.io/bs-material-ui',
  baseUrl: '/bs-material-ui/',
  favicon: 'img/favicon.png',
  organizationName: 'jsiebern', // Usually your GitHub org/user name.
  projectName: 'bs-material-ui', // Usually your repo name.
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
      title: 'BS Material UI',
      logo: {
        alt: 'BS Material UI Logo',
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
