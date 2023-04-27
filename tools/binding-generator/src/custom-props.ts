const target = {
  type: {
    name: 'string',
  },
  required: false,
  description: '-',
};

const rel = {
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
};

const inputRef = {
  type: {
    name: 'custom',
    reasonType: 'ReactDOM.domRef',
    jsType: 'ReactDOM.domRef',
  },
  required: false,
  description: '-',
};

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
    onMouseEnter: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    onMouseLeave: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    inputRef: inputRef,
  },
  FormControlLabel: {
    inputRef: {
      type: {
        name: 'custom',
        reasonType: 'ReactDOM.domRef',
        jsType: 'ReactDOM.domRef',
      },
      required: false,
      description: '-',
    },
  },
  Checkbox: {
    inputRef,
  },
  Radio: {
    inputRef,
  },
  Switch: {
    inputRef,
  },
  OutlinedInput: {
    inputRef,
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
    onRowsPerPageChange: {
      type: {
        name: 'custom',
        reasonType: '{..} => unit',
        jsType: '{..} => unit',
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
    rowSpan: {
      type: {
        name: 'int',
      },
      required: false,
      description: '-',
    },
  },
  TableRow: {
    onClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
    onDoubleClick: {
      type: {
        name: 'func',
      },
      required: false,
      description: '-',
    },
  },
  MuiThemeProvider: {
    theme: {
      type: {
        name: 'custom',
        reasonType: 'Theme.t',
        jsType: 'Theme.t',
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
                name: 'custom',
                reasonType: 'ReactEvent.Form.t',
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
    onChangeCommitted: {
      type: {
        name: 'signature',
        type: 'function',
        signature: {
          arguments: [
            {
              name: 'event',
              type: {
                name: 'custom',
                reasonType: 'ReactEvent.Form.t',
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
    target,
    rel,
  },
  ButtonBase: {
    target,
    rel,
  },
  Button: {
    target,
    rel,
  },
  Collapse: {
    mountOnEnter: {
      type: {
        name: 'boolean',
      },
      required: false,
      description: '-',
    },
    unmountOnExit: {
      type: {
        name: 'boolean',
      },
      required: false,
      description: '-',
    },
    appear: {
      type: {
        name: 'boolean',
      },
      required: false,
      description: '-',
    },
    enter: {
      type: {
        name: 'boolean',
      },
      required: false,
      description: '-',
    },
    exit: {
      type: {
        name: 'boolean',
      },
      required: false,
      description: '-',
    },
  },
  TreeView: {
    onNodeFocus: {
      type: {
        name: 'custom',
        reasonType: '({..}, string) => unit',
        jsType: '({..}, string) => unit',
      },
      required: false,
      description: '-',
    },
    onNodeSelect: {
      type: {
        name: 'custom',
        reasonType: '({..}, array<string>) => unit',
        jsType: '({..}, array<string>) => unit',
      },
      required: false,
      description: '-',
    },
    onNodeToggle: {
      type: {
        name: 'custom',
        reasonType: '({..}, array<string>) => unit',
        jsType: '({..}, array<string>) => unit',
      },
      required: false,
      description: '-',
    },
  },

  // --------------------- Lab

  Rating: {
    name: {
      type: {
        name: 'string',
      },
      required: false,
      description: '-',
    },
    onChangeActive: {
      type: {
        name: 'custom',
        reasonType: '({..}, int) => unit',
        jsType: '({..}, int) => unit',
      },
      required: false,
      description: '-',
    },
  },

  Pagination: {
    renderItem: {
      type: {
        name: 'signature',
        type: 'function',
        raw: '',
        signature: {
          arguments: [
            {
              name: 'params',
              type: {
                name: 'shape',
                value: {
                  color: {
                    name: 'enum',
                    value: [
                      { value: "'primary'", computed: false },
                      { value: "'secondary'", computed: false },
                      { value: "'standard'", computed: false },
                    ],
                    required: true,
                  },
                  shape: {
                    name: 'enum',
                    value: [
                      { value: "'round'", computed: false },
                      { value: "'rounded'", computed: false },
                    ],
                    required: true,
                  },
                  size: {
                    name: 'enum',
                    value: [
                      { value: "'large'", computed: false },
                      { value: "'medium'", computed: false },
                      { value: "'small'", computed: false },
                    ],
                    required: true,
                  },
                  variant: {
                    name: 'enum',
                    value: [
                      { value: "'outlined'", computed: false },
                      { value: "'text'", computed: false },
                    ],
                    required: true,
                  },
                  page: { name: 'int' },
                  selected: { name: 'boolean' },
                  disabled: { name: 'boolean' },
                },
              },
              required: true,
            },
          ],
          return: {
            name: 'Node',
          },
        },
      },
      required: false,
      description: '-',
    },
  },
  Autocomplete: {
    getOptionDisabled: {
      type: {
        name: 'custom',
        reasonType: "'t => bool",
        jsType: "'t => bool",
      },
      required: false,
      description: '-',
    },
    getOptionLabel: {
      type: {
        name: 'custom',
        reasonType: "'t => string",
        jsType: "'t => string",
      },
      required: false,
      description: '-',
    },
    getOptionSelected: {
      type: {
        name: 'custom',
        reasonType: "('t, 't) => string",
        jsType: "('t, 't) => string",
      },
      required: false,
      description: '-',
    },
    groupBy: {
      type: {
        name: 'custom',
        reasonType: "'t => string",
        jsType: "'t => string",
      },
      required: false,
      description: '-',
    },
    isOptionEqualToValue: {
      type: {
        name: 'custom',
        reasonType: "('t, 't) => bool",
        jsType: "('t, 't) => bool",
      },
      required: false,
      description: '-',
    },
    renderOption: {
      type: {
        name: 'custom',
        reasonType: "('t, {..}) => React.element",
        jsType: "('t, {..}) => React.element",
      },
      required: false,
      description: '-',
    },
    renderGroup: {
      type: {
        name: 'custom',
        reasonType: `{..} => React.element`,
        jsType: `{..} => React.element`,
      },
      required: false,
      description: '-',
    },
    renderTags: {
      type: {
        name: 'custom',
        reasonType: `(array<'t>, {. "index": int} => unit) => React.element`,
        jsType: `(array<'t>, {. "index": int} => unit) => React.element`,
      },
      required: false,
      description: '-',
    },
    value: {
      type: {
        name: 'any',
      },
      required: false,
      description: '-',
    },
    onHighlightChange: {
      type: {
        name: 'custom',
        reasonType: "({..}, 't, string) => unit",
        jsType: "({..}, 't, string) => unit",
      },
      required: false,
      description: '-',
    },
    onInputChange: {
      type: {
        name: 'custom',
        reasonType: '({..}, string, string) => unit',
        jsType: '({..}, string, string) => unit',
      },
      required: false,
      description: '-',
    },
  },
};
