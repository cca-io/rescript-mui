import { parse as parseDoctrine } from 'doctrine';
// @ts-ignore
import * as Console from './../../helpers/console';
// import { generateAny } from './helpers';
import { isCallBackName, isPropType } from '../../helpers/identify-prop-type';
import Base from './base';
import FunctionSignatureFactory from './_function';

enum CallbackTypes {
  ClipboardCallback = 'ReactEvent.Clipboard.t',
  CompositionCallback = 'ReactEvent.Composition.t',
  KeyboardCallback = 'ReactEvent.Keyboard.t',
  FocusCallback = 'ReactEvent.Focus.t',
  FormCallback = 'ReactEvent.Form.t',
  MouseCallback = 'ReactEvent.Mouse.t',
  SelectionCallback = 'ReactEvent.Selection.t',
  TouchCallback = 'ReactEvent.Touch.t',
  UICallback = 'ReactEvent.UI.t',
  WheelCallback = 'ReactEvent.Wheel.t',
  MediaCallback = 'ReactEvent.Media.t',
  ImageCallback = 'ReactEvent.Image.t',
  AnimationCallback = 'ReactEvent.Animation.t',
  TransitionCallback = 'ReactEvent.Transition.t',
  SyntheticCallback = 'ReactEvent.Synthetic.t',
  GenericCallback = 'Types.any',
}

// @ts-ignore
const getCallbackType = (propName: string) => {
  switch (propName) {
    /* Clipboard events */
    case 'onCopy':
    case 'onCut':
    case 'onPaste':
      return CallbackTypes.ClipboardCallback;
    /* Composition events */
    case 'onCompositionEnd':
    case 'onCompositionStart':
    case 'onCompositionUpdate':
      return CallbackTypes.CompositionCallback;
    /* Keyboard events */
    case 'onKeyDown':
    case 'onKeyPress':
    case 'onKeyUp':
      return CallbackTypes.KeyboardCallback;
    /* Focus events */
    case 'onFocus':
    case 'onBlur':
      return CallbackTypes.FocusCallback;
    /* Form events */
    case 'onChange':
    case 'onInput':
    case 'onSubmit':
      return CallbackTypes.FormCallback;
    /* Mouse events */
    case 'onClick':
    case 'onContextMenu':
    case 'onDoubleClick':
    case 'onDrag':
    case 'onDragEnd':
    case 'onDragEnter':
    case 'onDragExit':
    case 'onDragLeave':
    case 'onDragOver':
    case 'onDragStart':
    case 'onDrop':
    case 'onMouseDown':
    case 'onMouseEnter':
    case 'onMouseLeave':
    case 'onMouseMove':
    case 'onMouseOut':
    case 'onMouseOver':
    case 'onMouseUp':
      return CallbackTypes.MouseCallback;
    /* Selection events */
    case 'onSelect':
      return CallbackTypes.SelectionCallback;
    /* Touch events */
    case 'onTouchCancel':
    case 'onTouchEnd':
    case 'onTouchMove':
    case 'onTouchStart':
      return CallbackTypes.TouchCallback;
    /* UI events */
    case 'onScroll':
      return CallbackTypes.UICallback;
    /* Wheel events */
    case 'onWheel':
      return CallbackTypes.WheelCallback;
    /* Media events */
    case 'onAbort':
    case 'onCanPlay':
    case 'onCanPlayThrough':
    case 'onDurationChange':
    case 'onEmptied':
    case 'onEncrypetd':
    case 'onEnded':
    case 'onError':
    case 'onLoadedData':
    case 'onLoadedMetadata':
    case 'onLoadStart':
    case 'onPause':
    case 'onPlay':
    case 'onPlaying':
    case 'onProgress':
    case 'onRateChange':
    case 'onSeeked':
    case 'onSeeking':
    case 'onStalled':
    case 'onSuspend':
    case 'onTimeUpdate':
    case 'onVolumeChange':
    case 'onWaiting':
      return CallbackTypes.MediaCallback;
    /* Image events */
    case 'onLoad':
      return CallbackTypes.ImageCallback;
    /* Animation events */
    case 'onAnimationStart':
    case 'onAnimationEnd':
    case 'onAnimationIteration':
      return CallbackTypes.AnimationCallback;
    /* Transition events */
    case 'onTransitionEnd':
      return CallbackTypes.TransitionCallback;
    /* Material UI Specific */
    case 'onBackdropClick':
    case 'onClickAway':
      return CallbackTypes.MouseCallback;
    case 'onEscapeKeyUp':
    case 'onEscapeKeyDown':
      return CallbackTypes.KeyboardCallback;
    case 'onKeyboardFocus':
      return CallbackTypes.FocusCallback;
    case 'onClose':
    case 'onEnter':
    case 'onEntered':
    case 'onEntering':
    case 'onExit':
    case 'onExited':
    case 'onExiting':
    case 'onClean':
    case 'onDirty':
    case 'onRendered':
    case 'onOpen':
    case 'onDelete':
      return CallbackTypes.SyntheticCallback;
    case 'onChangePage':
      return CallbackTypes.MouseCallback;
    case 'onChangeRowsPerPage':
      return CallbackTypes.FormCallback;
    default:
      return CallbackTypes.GenericCallback;
  }
};

const factory = (propertyType: PropType$Func) => {
  return class PrimitiveParser extends Base {
    // @ts-ignore
    private _propertyType: PropType$Func = propertyType;

    public executeParse() {
      const parsed = parseDoctrine(this.property.description, {
        sloppy: true,
      });
      parsed.tags = parsed.tags.filter(
        (arg) => arg.title === 'param' || arg.title === 'returns',
      );
      let parsedArgs: any[] = [];
      let parsedReturns: PropType | null = null;
      const callback = getCallbackType(this.property.name);

      if (parsed.tags.length > 0) {
        const parsedLength = parsed.tags.length;
        if (parsed.tags[parsedLength - 1].title === 'returns') {
          parsedArgs = parsed.tags.slice(0, parsedLength - 1);
          const r = parsed.tags[parsedLength - 1].type;
          parsedReturns = isPropType(r) ? r : null;
        } else {
          parsedArgs = parsed.tags;
          parsedReturns = { name: 'void' };
        }

        if (isCallBackName(this.property.name)) {
          if (callback !== CallbackTypes.GenericCallback) {
            parsedArgs = parsedArgs.map((arg) =>
              arg.name === 'event'
                ? {
                    ...arg,
                    type: { ...arg.type, name: 'custom', reasonType: callback },
                  }
                : arg,
            );
          }
        }

        // Convert numbers to int (usually are index id's)
        parsedArgs = parsedArgs.map((arg) => {
          if (arg.type.name === 'number') {
            return { ...arg, type: { ...arg.type, name: 'int' } };
          } else if (arg.type.type === 'UnionType') {
            return {
              ...arg,
              type: {
                ...arg.type,
                type: 'Union',
                name: 'union',
                value: arg.type.elements.map((el: any) => {
                  if (
                    el.type === 'TypeApplication' &&
                    el.expression.name === 'Array'
                  ) {
                    return {
                      name: 'arrayOf',
                      value: {
                        name: el.applications[0].name,
                      },
                    };
                  }
                  if (typeof el.name !== 'undefined') {
                    return {
                      name: el.name.replace('number', 'int'),
                    };
                  }
                  return el;
                }),
              },
            };
          }
          return arg;
        });

        if (parsedReturns != null) {
          const functionSig: PropType$FunctionSignature = {
            name: 'signature',
            type: 'function',
            raw: '',
            signature: {
              arguments: parsedArgs.map((arg) => {
                if (arg.type.type === 'OptionalType') {
                  arg.type.name = arg.type.expression.name;
                }
                if (arg.type.type === 'AllLiteral') {
                  arg.type.name = 'any';
                }
                return {
                  name: arg.name,
                  type: arg.type,
                  required: arg.type.type !== 'OptionalType',
                };
              }),
              return: parsedReturns,
            },
          };

          const factory = FunctionSignatureFactory(functionSig);
          const parsedSig = new factory(this.property, 'moduleOnly');
          parsedSig.parse();

          this._reasonType = parsedSig.reasonType;
          return;
        }
      } else {
        if (callback !== CallbackTypes.GenericCallback) {
          this._reasonType = `${callback} => unit`;
          return;
        }
      }

      this._reasonType = CallbackTypes.GenericCallback;
    }
  };
};

export default factory;
