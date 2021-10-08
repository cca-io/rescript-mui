// ReScript syntax support for PrismJS (https://prismjs.com/) - experimental (but better than nothing)

Prism.languages.rescript = Prism.languages.extend('clike', {
  string: {
    pattern: /"(?:\\(?:\r\n|[\s\S])|[^\\\r\n"])*"/,
    greedy: true,
  },
  // 'class-name' must be matched *after* 'constructor' defined below
  'class-name': /\b[A-Z]\w*/,
  keyword: /\b(?:and|as|assert|constraint|downto|else|exception|external|false|for|if|in|include|lazy|let|module|mutable|of|open|rec|switch|to|true|try|type|when|while|with)\b/,
  operator: /\.{3}|:[:=]|\|>|->|=(?:==?|>)?|<=?|>=?|[|^?'#!~`]|[+\-*\/]\.?|\b(?:asr|land|lor|lsl|lsr|lxor|mod)\b/,
});

Prism.languages.insertBefore('rescript', 'string', {
  'template-string': {
    pattern: /`(?:\\[\s\S]|\$\{(?:[^{}]|\{(?:[^{}]|\{[^}]*\})*\})+\}|(?!\$\{)[^\\`])*`/,
    greedy: true,
    inside: {
      'template-punctuation': {
        pattern: /^`|`$/,
        alias: 'string',
      },
      interpolation: {
        pattern: /((?:^|[^\\])(?:\\{2})*)\$\{(?:[^{}]|\{(?:[^{}]|\{[^}]*\})*\})+\}/,
        lookbehind: true,
        inside: {
          'interpolation-punctuation': {
            pattern: /^\$\{|\}$/,
            alias: 'punctuation',
          },
          rest: Prism.languages.rescript,
        },
      },
      string: /[\s\S]+/,
    },
  },
});

Prism.languages.insertBefore('rescript', 'class-name', {
  character: {
    pattern: /'(?:\\x[\da-f]{2}|\\o[0-3][0-7][0-7]|\\\d{3}|\\.|[^'\\\r\n])'/,
    alias: 'string',
  },
  constructor: {
    // Negative look-ahead prevents from matching things like String.capitalize
    pattern: /\b[A-Z]\w*\b(?!\s*\.)/,
    alias: 'variable',
  },
  label: {
    pattern: /\b[a-z]\w*(?=::)/,
    alias: 'symbol',
  },
});

// We can't match functions properly, so let's not even try.
delete Prism.languages.rescript.function;
