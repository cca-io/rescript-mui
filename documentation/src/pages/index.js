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
                alt="Graphql-ppx"
                className={styles.heroLogo}
                src={useBaseUrl('img/logo.svg')}
                style={{ maxWidth: '250px' }}
              />
              Bindings for{' '}
              <span className={styles.heroProjectKeywords}>Material UI</span>
              <br /> in ReasonML
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
                  src="https://ghbtns.com/github-btn.html?user=jsiebern&amp;repo=bs-material-ui&amp;type=star&amp;count=true&amp;size=large"
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
                  Language level GraphQL primitives
                </h2>
                <p className="padding-horiz--md">
                  graphql-ppx offers language level GraphQL primitives within
                  ReasonML using a compiler preprocessor extension. This means
                  you have a simple syntax to define queries, mutations and
                  fragments in your ReasonML project.
                </p>
              </section>
              <section className="col">
                <h2 className={styles.featureHeading}>
                  Building block for GraphQL clients
                </h2>
                <p className="padding-horiz--md">
                  graphql-ppx automatically generates types, and parse/serialize
                  functions for converting GraphQL data and arguments to
                  idiomatic ReasonML data structures. This provides a building
                  block for GraphQL clients in the ReasonML ecosystem.
                </p>
              </section>
              <section className="col">
                <h2 className={styles.featureHeading}>100% type safe!</h2>
                <p className="padding-horiz--md">
                  With graphql-ppx your project is completely type safe. Types
                  are generated from the GraphQL schema of your backend. This
                  means that no runtime errors occur when working with server
                  data. And if a schema change breaks your app, your app simply
                  won't compile!
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
