import * as React from 'react';
import { withStyles } from '@material-ui/core/styles';

export const createStyled = (styles) => withStyles(styles)(props => props.children({ 'classes': props.classes }));