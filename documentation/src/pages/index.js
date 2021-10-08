import React from 'react';
import Layout from '@theme/Layout';
import Link from '@docusaurus/Link';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import useBaseUrl from '@docusaurus/useBaseUrl';
import styles from './styles.module.css';

function Home() {
  const context = useDocusaurusContext();
  const { siteConfig = {} } = context;
  return (
    <Layout
      permalink="/"
      title={siteConfig.tagline}
      description={siteConfig.description}
    >
      <main>
        <div className={styles.hero}>
          <div className={styles.heroInner}>
            <h1 className={styles.heroProjectTagline}>
              <img
                alt="ReScript Material-UI"
                className={styles.heroLogo}
                src={useBaseUrl('img/logo.svg')}
                style={{ maxWidth: '250px' }}
              />
              Bindings for{' '}
              <a href="https://material-ui.com" target="_blank">
                Material UI
              </a>
              <br /> in{' '}
              <a href="https://rescript-lang.org/" target="_blank">
                ReScript
              </a>
              <br />
              <br />
            </h1>
            <div className={styles.indexCtas}>
              <Link
                className={styles.indexCtasGetStartedButton}
                to={useBaseUrl('docs/introduction')}
              >
                Get Started
              </Link>
              <span className={styles.indexCtasGitHubButtonWrapper}>
                <iframe
                  className={styles.indexCtasGitHubButton}
                  src="https://ghbtns.com/github-btn.html?user=cca-io&amp;repo=rescript-material-ui&amp;type=star&amp;count=true&amp;size=large"
                  width={160}
                  height={30}
                  title="GitHub Stars"
                />
              </span>
            </div>
          </div>
        </div>
        <div className={styles.section}>
          <div className="container text--center margin-bottom--xl">
            <div className="row">
              <section className="col">
                <h2 className={styles.featureHeading}>
                  Automatically Generated
                </h2>
                <p className="padding-horiz--md">
                  All bindings to the Material-UI components are automatically
                  generated from the original documentation. They are extracted
                  & rendered by a combination of custom-built typescript tools.
                </p>
              </section>
              <section className="col">
                <h2 className={styles.featureHeading}>Actively maintained</h2>
                <p className="padding-horiz--md">
                  We (cca.io) use these bindings daily in various production
                  projects. This incentivizes us to regularly update the
                  bindings and to keep breaking changes to a minimum whereever
                  possible.
                </p>
              </section>
            </div>
          </div>
        </div>
      </main>
    </Layout>
  );
}

export default Home;
