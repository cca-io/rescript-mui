export default {
  Input: {
    inputComponent: {
      type: {
        name: 'any',
      },
      required: false,
      description: '-',
    },
  },
  MenuItem: {
    value: {
      type: {
        name: 'union',
        value: [
          {
            name: 'string',
          },
          {
            name: 'number',
          },
          {
            name: 'arrayOf',
            value: {
              name: 'string',
            },
          },
        ],
      },
      required: false,
      description: '-',
    },
    onFocus: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    onClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
  },
  Select: {
    value: {
      type: {
        name: 'union',
        value: [
          {
            name: 'string',
          },
          {
            name: 'number',
          },
          {
            name: 'arrayOf',
            value: {
              name: 'string',
            },
          },
        ],
      },
      required: false,
      description: '-',
    },
  },
  TextField: {
    value: {
      type: {
        name: 'union',
        value: [
          {
            name: 'string',
          },
          {
            name: 'number',
          },
        ],
      },
      required: false,
      description: '-',
    },
    defaultValue: {
      type: {
        name: 'union',
        value: [
          {
            name: 'string',
          },
          {
            name: 'number',
          },
        ],
      },
      required: false,
      description: '-',
    },
  },
  CardContent: {
    children: {
      type: {
        name: 'node',
      },
      required: false,
      description: '-',
    },
  },
  Card: {
    children: {
      type: {
        name: 'node',
      },
      required: false,
      description: '-',
    },
  },
  List: {
    children: {
      type: {
        name: 'node',
      },
      required: false,
      description: '-',
    },
  },
  ListItem: {
    value: {
      type: {
        name: 'union',
        value: [
          {
            name: 'string',
          },
          {
            name: 'number',
          },
          {
            name: 'arrayOf',
            value: {
              name: 'string',
            },
          },
        ],
      },
      required: false,
      description: '-',
    },
    onFocus: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    onClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
  },
  Menu: {
    anchorEl: {
      type: {
        name: 'any',
      },
      required: false,
      description: '-',
    },
  },
  Popover: {
    anchorEl: {
      type: {
        name: 'union',
        value: [{ name: 'object' }, { name: 'func' }],
      },
      required: false,
      description: '-',
    },
  },
  Popper: {
    anchorEl: {
      type: {
        name: 'union',
        value: [{ name: 'object' }, { name: 'func' }],
      },
      required: false,
      description: '-',
    },
  },
  TablePagination: {
    labelRowsPerPage: {
      type: {
        name: 'custom',
        reasonType:
          '({. "from": int, "to": int, "count": int, "page": int}) => React.element',
        jsType: "'labelRowsPerPage",
      },
      required: false,
      description: '-',
    },
    labelDisplayedRows: {
      type: {
        name: 'custom',
        reasonType: '({. "from": int, "to": int, "count": int}) => string',
        jsType: "'labelDisplayedRows",
      },
      required: false,
      description: '-',
    },
    rowsPerPageOptions: {
      type: {
        name: 'arrayOf',
        value: {
          name: 'int',
        },
      },
      required: false,
      description: '-',
    },
    page: {
      type: {
        name: 'int',
      },
      required: false,
      description: '-',
    },
  },
  TableCell: {
    colSpan: {
      type: {
        name: 'int',
      },
      required: false,
      description: '-',
    },
  },
  TableRow: {
    onDoubleClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
  },
  Grid: {
    xsAuto: {
      type: {
        name: 'bool',
      },
      required: false,
      description: '-',
      reasonOnly: true,
    },
    smAuto: {
      type: {
        name: 'bool',
      },
      required: false,
      description: '-',
      reasonOnly: true,
    },
    mdAuto: {
      type: {
        name: 'bool',
      },
      required: false,
      description: '-',
      reasonOnly: true,
    },
    lgAuto: {
      type: {
        name: 'bool',
      },
      required: false,
      description: '-',
      reasonOnly: true,
    },
    xlAuto: {
      type: {
        name: 'bool',
      },
      required: false,
      description: '-',
      reasonOnly: true,
    },
  },
  MuiThemeProvider: {
    theme: {
      type: {
        name: 'custom',
        reasonType: 'MaterialUi_Theme.t',
        jsType: 'MaterialUi_Theme.t',
      },
      required: true,
      description: '-',
    },
  },
  InputLabel: {
    htmlFor: {
      type: {
        name: 'string',
      },
      required: true,
      description: '-',
    },
  },
  Slider: {
    onChange: {
      type: {
        name: 'signature',
        type: 'function',
        signature: {
          arguments: [
            {
              name: 'event',
              type: {
                name: 'object',
              },
              required: true,
            },
            {
              name: 'value',
              type: { name: 'int' },
              required: true,
            },
          ],
          return: {
            name: 'void',
          },
        },
      },
      required: false,
      description: '-',
    },
  },
  Link: {
    onClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    href: {
      type: {
        name: 'string',
      },
      required: false,
      description: '-',
    },
    target: {
      type: {
        name: 'string',
      },
      required: false,
      description: '-',
    },
    rel: {
      type: {
        name: 'enum',
        value: [
          { value: 'alternate', computed: false },
          { value: 'author', computed: false },
          { value: 'bookmark', computed: false },
          { value: 'external', computed: false },
          { value: 'help', computed: false },
          { value: 'license', computed: false },
          { value: 'next', computed: false },
          { value: 'nofollow', computed: false },
          { value: 'noreferrer', computed: false },
          { value: 'noopener', computed: false },
          { value: 'prev', computed: false },
          { value: 'search', computed: false },
          { value: 'tag', computed: false },
        ],
      },
      required: false,
      description: '-',
    },
  },
};
