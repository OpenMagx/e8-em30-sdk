/*****************************************************************************
 *
 *  tsunicde.c - Declares Unicode properties interface.
 *
 *  Copyright (C) 2002-2005 Monotype Imaging Inc. All rights reserved.
 *
 *  $Archive:   I:/BULL/DisplayImaging/archives/wtle/product/source/privincl/tsunicde.h_v  $ 
 *  $Date:   Apr 05 2006 07:50:08  $
 *  $Revision:   1.43.1.0  $
 *
 ****************************************************************************/

#ifndef TSUNICDE_H
#define TSUNICDE_H

#include "tstypes.h"

TS_BEGIN_HEADER

/* joining type */
#define TSPROPS_JT_MASK          0x00003800
#define TSPROPS_JT_SHIFT         11

/* joining group */
#define TSPROPS_JG_MASK          0x000007e0
#define TSPROPS_JG_SHIFT         5

/* line break types */
#define TSPROPS_LB_MASK          0x007C0000
#define TSPROPS_LB_SHIFT         18


/******************************************************************************
 *
 *  Enumeration of character categories.
 *
 *  <GROUP uniprops>
 *
 */
typedef enum
{
    TS_UNASSIGNED              = 0,    /* unassigned  */
    TS_GENERAL_OTHER_TYPES     = 0,    /* Cn  */
    TS_UPPERCASE_LETTER        = 1,    /* Lu  */
    TS_LOWERCASE_LETTER        = 2,    /* Ll  */
    TS_TITLECASE_LETTER        = 3,    /* Lt  */
    TS_MODIFIER_LETTER         = 4,    /* Lm  */
    TS_OTHER_LETTER            = 5,    /* Lo  */
    TS_NON_SPACING_MARK        = 6,    /* Mn  */
    TS_ENCLOSING_MARK          = 7,    /* Me  */
    TS_COMBINING_SPACING_MARK  = 8,    /* Mc  */
    TS_DECIMAL_DIGIT_NUMBER    = 9,    /* Nd  */
    TS_LETTER_NUMBER           = 10,   /* Nl  */
    TS_OTHER_NUMBER            = 11,   /* No  */
    TS_SPACE_SEPARATOR         = 12,   /* Zs  */
    TS_LINE_SEPARATOR_CHAR     = 13,   /* Zl  */
    TS_PARAGRAPH_SEPARATOR     = 14,   /* Zp  */
    TS_CONTROL_CHAR            = 15,   /* Cc  */
    TS_FORMAT_CHAR             = 16,   /* Cf  */
    TS_PRIVATE_USE_CHAR        = 17,   /* Co  */
    TS_SURROGATE               = 18,   /* Cs  */
    TS_DASH_PUNCTUATION        = 19,   /* Pd  */
    TS_START_PUNCTUATION       = 20,   /* Ps  */
    TS_END_PUNCTUATION         = 21,   /* Pe  */
    TS_CONNECTOR_PUNCTUATION   = 22,   /* Pc  */
    TS_OTHER_PUNCTUATION       = 23,   /* Po  */
    TS_MATH_SYMBOL             = 24,   /* Sm  */
    TS_CURRENCY_SYMBOL         = 25,   /* Sc  */
    TS_MODIFIER_SYMBOL         = 26,   /* Sk  */
    TS_OTHER_SYMBOL            = 27,   /* So  */
    TS_INITIAL_PUNCTUATION     = 28,   /* Pi  */
    TS_FINAL_PUNCTUATION       = 29   /* Pf  */
} TsCharCategory;



#define TS_UNICODE_CATEGORY(c)  (TsUnicode_getProps(c) &0x1f)


/******************************************************************************
 *
 *  Enumeration of shifts needed to access properties.
 *
 *  <GROUP uniprops>
 *
 */
enum TsPropsValues
{
    TSPROPS_EXCEPTION_SHIFT = 5,
    TSPROPS_BIDI_SHIFT,
    TSPROPS_MIRROR_SHIFT = TSPROPS_BIDI_SHIFT+5,
    TSPROPS_NUMERIC_TYPE_SHIFT,
    TSPROPS_RESERVED_SHIFT = TSPROPS_NUMERIC_TYPE_SHIFT+3,
    TSPROPS_VALUE_SHIFT = 20,
    TSPROPS_EXCEPTION_BIT = 1UL<<TSPROPS_EXCEPTION_SHIFT,
    TSPROPS_VALUE_BITS = 32-TSPROPS_VALUE_SHIFT,
    TSPROPS_MIN_VALUE = -(1L<<(TSPROPS_VALUE_BITS-1)),
    TSPROPS_MAX_VALUE = (1L<<(TSPROPS_VALUE_BITS-1))-1,
    TSPROPS_MAX_EXCEPTIONS_COUNT = 1L<<TSPROPS_VALUE_BITS
};

/******************************************************************************
 *
 *  Enumeration of properties.
 *
 *  <GROUP uniprops>
 *
 */
typedef enum 
{
    TSPROPS_ASCII_HEX_DIGIT,
    TSPROPS_BIDI_CONTROL,
    TSPROPS_DASH,
    TSPROPS_DEPRECATED,
    TSPROPS_DIACRITIC,
    TSPROPS_EXTENDER,
    TSPROPS_GRAPHEME_LINK,
    TSPROPS_HEX_DIGIT,
    TSPROPS_HYPHEN,
    TSPROPS_IDEOGRAPHIC,
    TSPROPS_IDS_BINARY_OPERATOR,
    TSPROPS_IDS_TRINARY_OPERATOR,
    TSPROPS_JOIN_CONTROL,
    TSPROPS_LOGICAL_ORDER_EXCEPTION,
    TSPROPS_NONCHARACTER_CODE_POINT,
    TSPROPS_OTHER_ALPHABETIC,
    TSPROPS_OTHER_DEFAULT_IGNORABLE_CODE_POINT,
    TSPROPS_OTHER_GRAPHEME_EXTEND,
    TSPROPS_OTHER_ID_START,
    TSPROPS_OTHER_LOWERCASE,
    TSPROPS_OTHER_MATH,
    TSPROPS_OTHER_UPPERCASE,
    TSPROPS_QUOTATION_MARK,
    TSPROPS_RADICAL,
    TSPROPS_SOFT_DOTTED,
    TSPROPS_STERM,
    TSPROPS_TERMINAL_PUNCTUATION,
    TSPROPS_UNIFIED_IDEOGRAPH,
    TSPROPS_VARIATION_SELECTOR,
    TSPROPS_WHITE_SPACE,
    TSPROPS_XID_CONTINUE,
    TSPROPS_XID_START
} TsPropType;


/******************************************************************************
 *
 *  Enumeration of line break types.
 *
 *  <GROUP uniprops>
 *
 */
typedef enum
{
    /* AI */ TS_LB_AMBIGUOUS,         /* act like AL when the resolved EAW is N otherwise act as ID */
    /* AL */ TS_LB_ALPHABETIC,        /* are alphabetic characters or symbols that are used with alphabetic characters */
    /* B2 */ TS_LB_BREAK_BOTH,        /* provide a line break opportunity before and after the character */
    /* BA */ TS_LB_BREAK_AFTER,       /* generally provide a line break opportunity after the character */
    /* BB */ TS_LB_BREAK_BEFORE,      /* generally provide a line break opportunity before the character */
    /* BK */ TS_LB_MANDATORY_BREAK,   /* cause a line break (after) */
    /* CB */ TS_LB_CONTINGENT_BREAK,  /* provide a line break opportunity contingent on additional information */
    /* CL */ TS_LB_CLOSE_PUNCTUATION, /* prohibit a line break before */
    /* CM */ TS_LB_COMBINING_MARK,    /* prohibit a line break between the character and the preceding character */
    /* CR */ TS_LB_CARRIAGE_RETURN,   /* cause a line break (after), except between CR and LF */
    /* EX */ TS_LB_EXCLAMATION,       /* prohibit line break before */
    /* GL */ TS_LB_GLUE,              /* prohibit line breaks before or after */
    /* HY */ TS_LB_HYPHEN,            /* provide a line break opportunity after the character, except in numeric context */
    /* ID */ TS_LB_IDEOGRAPHIC,       /* break before or after, except in some numeric context */
    /* IN */ TS_LB_INSEPERABLE,       /* allow only indirect line breaks between pairs */
    /* IS */ TS_LB_INFIX_NUMERIC,     /* prevent breaks after any and before numeric */
    /* LF */ TS_LB_LINE_FEED,         /* cause a line break (after) */
    /* NL */ TS_LB_NEXT_LINE,         /* cause a line break (after) */
    /* NS */ TS_LB_NONSTARTER,        /* (e.g. small kana) allow only indirect line break before */
    /* NU */ TS_LB_NUMERIC,           /* form numeric expressions for line breaking purposes */
    /* OP */ TS_LB_OPEN_PUNCTUATION,  /* prohibit a line break after */
    /* PO */ TS_LB_POSTFIX_NUMERIC,   /* do not break following a numeric expression */
    /* PR */ TS_LB_PREFIX_NUMERIC,    /* don't break in front of a numeric expression */
    /* QU */ TS_LB_QUOTATION,         /* act like they are both opening and closing */
    /* SA */ TS_LB_COMPLEX_CONTEXT,   /* provide a line break opportunity contingent on additional, language specific context analysis */
    /* SG */ TS_LB_SURROGATE,         /* should not occur in well-formed text */
    /* SP */ TS_LB_SPACE,             /* generally provide a line break opportunity after the character, enable indirect breaks */
    /* SY */ TS_LB_BREAK_SYMBOLS,     /* prevent a break before, and allow a break after */
    /* WJ */ TS_LB_WORD_JOINER,       /* prohibit line breaks before or after */
    /* XX */ TS_LB_UNKNOWN,           /* are all characters with (as yet) unknown line breaking behavior or unassigned code positions */
    /* ZW */ TS_LB_ZWSPACE            /* provide a break opportunity */
} TsLineBreakType;

/* Several Unicode characters */

#define TS_TAB              0x0009  /* CHARACTER TABULATION */
#define TS_CR               0x000D  /* CARRIAGE RETURN */
#define TS_LF               0x000A  /* LINE FEED */
#define TS_SECTION_SIGN     0x00A7  /* SECTION SIGN */

#define TS_CGJ              0x034F  /* COMBINING GRAPHEME JOINER */
#define TS_ZERO_WIDTH_SPACE 0x200B  /* ZERO WIDTH SPACE */
#define TS_ZWJ              0x200D  /* ZERO WIDTH JOINER */
#define TS_LEFT_TO_RIGHT_MARK 0x200E  /* LEFT TO RIGHT MARK */ 
#define TS_RIGHT_TO_LEFT_MARK 0x200F  /* RIGHT TO LEFT MARK */ 
#define TS_ZWNJ             0x200C  /* ZERO WIDTH NON_JOINER */
#define TS_LINE_SEPARATOR   0x2028  /* LINE SEPARATOR */
#define TS_DOTTED_CIRCLE    0x25CC  /* DOTTED CIRCLE */

#define TS_DEV_RA           0x0930  /* DEVANAGARI LETTER RA*/
#define TS_DEV_RRA          0x0931  /* DEVANAGARI LETTER RRA */
#define TS_DEV_HALANT       0x094D  /* DEVANAGARI SIGN VIRAMA */

#define TS_BEN_RA           0x09B0  /* BENGALI LETTER RA */
#define TS_BEN_HALANT       0x09CD  /* BENGALI SIGN VIRAMA */ 

#define TS_TAM_RA           0x0BB0  /* TAMIL LETTER RA */
#define TS_TAM_HALANT       0x0BCD  /* TAMIL SIGN VIRAMA */

#define TS_THAI_CHARACTER_SARA_AM     0x0E33  /* THAI CHARACTER SARA AM */


#define TS_POSTAL_MARK      0x3012   /* POSTAL MARK */
#define TS_COMMERCIAL_AT    0x0040   /* COMMERCIAL AT */
#define TS_NUMBER_SIGN      0x0023   /* NUMBER SIGN */

/******************************************************************************
 *
 *  Enumeration of joining types.
 *
 *  <GROUP uniprops>
 *
 */
typedef enum
{
    TS_JT_NON_JOINING,      /* Does not have a joining form */
    TS_JT_JOIN_CAUSING,     /* ZWJ and tatweel (kashida) */
    TS_JT_DUAL_JOINING,     /* Joins on either side */
    TS_JT_BEFORE_JOINING,   /* Joins to the following character */
    TS_JT_AFTER_JOINING,    /* Joins to the preceeding character */
    TS_JT_TRANSPARENT,       /* Has no effect on joining */
    TS_JT_COUNT
} TsJoiningType;


/******************************************************************************
 *
 *  Enumeration of BiDi character classes.
 *
 *  <GROUP uniprops>
 *
 */
typedef enum
{
    TS_LEFT_TO_RIGHT               = 0,     /* L  */
    TS_RIGHT_TO_LEFT               = 1,     /* R  */
    TS_EUROPEAN_NUMBER             = 2,     /* EN  */
    TS_EUROPEAN_NUMBER_SEPARATOR   = 3,     /* ES  */
    TS_EUROPEAN_NUMBER_TERMINATOR  = 4,     /* ET  */
    TS_ARABIC_NUMBER               = 5,     /* AN  */
    TS_COMMON_NUMBER_SEPARATOR     = 6,     /* CS  */
    TS_BLOCK_SEPARATOR             = 7,     /* B  */ /* aka "paragraph separator" */
    TS_SEGMENT_SEPARATOR           = 8,     /* S  */
    TS_WHITE_SPACE_NEUTRAL         = 9,     /* WS  */
    TS_OTHER_NEUTRAL               = 10,    /* ON  */
    TS_LEFT_TO_RIGHT_EMBEDDING     = 11,    /* LRE  */
    TS_LEFT_TO_RIGHT_OVERRIDE      = 12,    /* LRO  */
    TS_RIGHT_TO_LEFT_ARABIC        = 13,    /* AL  */
    TS_RIGHT_TO_LEFT_EMBEDDING     = 14,    /* RLE  */
    TS_RIGHT_TO_LEFT_OVERRIDE      = 15,    /* RLO  */
    TS_POP_DIRECTIONAL_FORMAT      = 16,    /* PDF  */
    TS_DIR_NON_SPACING_MARK        = 17,    /* NSM  */
    TS_BOUNDARY_NEUTRAL            = 18,    /* BN  */
    TS_CHAR_DIRECTION_COUNT
} TsBidiCharClass;



/*****************************************************************************
 *
 *  Gets the Unicode properties of a Unicode character from the first trie,
 *  e.g. category out of Cc, Ll, Mc, Nd, Pc, Sc, Zl, etc. 
 *
 *  Parameters:
 *      c               - [in] Unicode character
 *
 *  Return value:
 *      Unicode properties.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsUInt32)
TsUnicode_getProps(TsUInt32 c);


/*****************************************************************************
 *
 *  Gets the Unicode properties of a Unicode character from the second trie,
 *  e.g. line breaking type, joining type, PropList.txt category.  
 *
 *  Parameters:
 *      c               - [in] Unicode character
 *      column          - [in] column:
 *                             0 = get line breaking type
 *                             1 = get category from PropList.txt
 *                             2 = get joining type
 *
 *  Return value:
 *      Unicode properties.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsUInt32)
TsUnicode_getProps2(TsUInt32 c, TsInt32 column);


/*****************************************************************************
 *
 *  Gets the particular Bidi character type
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *      mgr             - [in] Unicode manager
 *
 *  Return value:
 *      TsBidiCharDirection result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBidiCharClass)
TsUnicode_getBidiCharType(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a lower case letter.
 *
 *  Parameters:
 *      c               - [in] Unicode character
 *
 *  Return value:
 *      TRUE if character is lower case, else FALSE
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isLower(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is an upper case letter.
 *
 *  Parameters:
 *      c               - [in] Unicode character
 *
 *  Return value:
 *      TRUE if character is upper case, else FALSE
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isUpper(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a title case letter, 
 *  usually upper case letters.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isTitleCase(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is katakana.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isKatakana(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a decimal digit.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isDigit(TsUInt32 c);


/*****************************************************************************
 *
 * Checks if the Unicode character is a letter -- based on UnicodeData.txt
 *
 *  Note:
 *      LineBreak.txt and UnicodeData.txt have different ideas about what is alphabetic
 *
 *  See also:
 *      TsUnicode_isAlphaForLineBreaking()
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isAlpha(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a letter or a decimal digit
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TRUE if character is a letter or a decimal digit, else FALSE.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isAlNum(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a number separator
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isNumInfix(TsUInt32 c);

/*****************************************************************************
 *
 *  Checks if Unicode character is a numeric prefix (e.g. '$')
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isNumPrefix(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a numeric postfix (e.g. '%')
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isNumPostfix(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a glue character (for line breaking).
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TRUE if line breaking type is "GL" ("Glue").
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isGlue(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is ambiguous (in terms of line-breaking properties)
 *
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isAmbiguous(TsUInt32 c);

/*****************************************************************************
 *
 *  Checks if Unicode character is ideographic (in terms of line-breaking properties)
 *
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isIdeographic(TsUInt32 c);

/*****************************************************************************
 *
 * Checks if Unicode character is alphabetic for line-breaking purposes -- based on LineBreak.txt
 *
 * Note:
 *     LineBreak.txt and UnicodeData.txt have different ideas about what is alphabetic
 *
 * See also:
 *     TsUnicode_isAlpha()
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isAlphaForLineBreaking(TsUInt32 c);


/*****************************************************************************
 *
 * Checks if ch is numeric for line-breaking (and word-breaking) purposes -- based on LineBreak.txt.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isNumericForLineBreaking(TsUInt32 c);


/*****************************************************************************
 *
 * Checks if Unicode character is alphabetic for word-breaking purposes.
 *
 * Note:
 *
 * See also:
 *     TsUnicode_isAlpha()
 *     TsUnicode_isAlphaForLineBreaking()
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isAlphaForWordBreaking(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is a hyphen (in terms of line-breaking properties)
 *
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isHyphen(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if Unicode character is defined.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isDefined(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a space character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isSpace(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a whitespace character.
 *  Similar to TsUnicode_isSpace(), but excludes
 *  U+00A0 "NO-BREAK SPACE", U+202F "NARROW NO-BREAK SPACE" and
 *  U+FEFF "ZERO WIDTH NO-BREAK SPACE".
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isWhitespace(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is printable.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isPrint(TsUInt32 c) ;


/*****************************************************************************
 *
 *  Checks if the Unicode character is non-spacing.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isNonSpacing(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is an open punctuation character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isOpenPunct(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a close punctuation character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isClosePunct(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is an initial punctuation character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isInitialPunct(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a final punctuation character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isFinalPunct(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a format character
 *  (category "Cf -- Other, Format").
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isFormat(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a quote character.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isQuote(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is a legal character at the end of a line.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *      bidiLevel       - [in] even if LTR, odd if RTL
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isLegalLineEndChar(TsUInt32 c, TsUInt8 bidiLevel); //CJC


/*****************************************************************************
 *
 *  Checks if the Unicode character forces the line to end.
 *
 *  Parameters:
 *      c                    - [in] Unicode character to check
 *      isOnGraphemeBoundary - [in] True if c is has its grapheme boundary flag set
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isRequiredLineEndChar(TsUInt32 c, TsBool isOnGraphemeBoundary);

/*****************************************************************************
 *
 *  Checks if the Unicode character is a legal character at the beginning of a line.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *      bidiLevel       - [in] even if LTR, odd if RTL
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isLegalLineStartChar(TsUInt32 c, TsUInt8 bidiLevel); //CJC


/*****************************************************************************
 *
 *  Checks if the Unicode character is a combining mark.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isCombiningMark(TsUInt32 c);


/*****************************************************************************
 *
 *  Returns the type of joining character (Unicode table 8-2).
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsJoiningType result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsJoiningType)
TsUnicode_getJoiningType(TsUInt32 c);


/*****************************************************************************
 *
 *  Returns the line break type.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsLineBreakType result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsLineBreakType)
TsUnicode_getLineBreakType(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character is mirrored.
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isMirrored(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character can be a base for a grapheme
 *  (e.g. Indic consonants).
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isGraphemeBase(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character can be a link for a grapheme
 *  (e.g. Indic virama).
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isGraphemeLink(TsUInt32 c);


/*****************************************************************************
 *
 *  Checks if the Unicode character can be an extender for a grapheme
 *  (e.g. Indic vowel marks).
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsBool result.
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsBool)
TsUnicode_isGraphemeExtend(TsUInt32 c);


/*****************************************************************************
 *
 *  Return bidi mirror for a character .
 *
 *  Parameters:
 *      c               - [in] Unicode character to check
 *
 *  Return value:
 *      TsUInt32 result (input character if no mirror).
 *
 *  <GROUP uniprops>
 */
TS_EXPORT(TsUInt32)
TsUnicode_getCharMirror(TsUInt32 c);

TS_END_HEADER

#endif /* TSUNICDE_H */

