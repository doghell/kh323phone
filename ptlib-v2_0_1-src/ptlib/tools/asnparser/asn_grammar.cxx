
/*  A Bison parser, made from asn_grammar.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	IDENTIFIER	258
#define	BIT_IDENTIFIER	259
#define	OID_IDENTIFIER	260
#define	IMPORT_IDENTIFIER	261
#define	MODULEREFERENCE	262
#define	TYPEREFERENCE	263
#define	OBJECTCLASSREFERENCE	264
#define	TYPEFIELDREFERENCE	265
#define	VALUEFIELDREFERENCE	266
#define	VALUESETFIELDREFERENCE	267
#define	OBJECTFIELDREFERENCE	268
#define	OBJECTSETFIELDREFERENCE	269
#define	OBJECTREFERENCE	270
#define	OBJECTSETREFERENCE	271
#define	INTEGER	272
#define	CSTRING	273
#define	OS_BSTRING	274
#define	BS_BSTRING	275
#define	OS_HSTRING	276
#define	BS_HSTRING	277
#define	STRING_BRACE	278
#define	BITSTRING_BRACE	279
#define	OID_BRACE	280
#define	ABSENT	281
#define	ABSTRACT_SYNTAX	282
#define	ALL	283
#define	ANY	284
#define	APPLICATION	285
#define	ASSIGNMENT	286
#define	AUTOMATIC	287
#define	BEGIN_t	288
#define	BIT	289
#define	BMPString	290
#define	BOOLEAN_t	291
#define	BY	292
#define	CHARACTER	293
#define	CHOICE	294
#define	CLASS	295
#define	COMPONENT	296
#define	COMPONENTS	297
#define	CONSTRAINED	298
#define	DEFAULT	299
#define	DEFINED	300
#define	DEFINITIONS	301
#define	EMBEDDED	302
#define	END	303
#define	ENUMERATED	304
#define	EXCEPT	305
#define	EXPLICIT	306
#define	EXPORTS	307
#define	EXTERNAL	308
#define	FALSE_t	309
#define	FROM	310
#define	GeneralString	311
#define	GraphicString	312
#define	IA5String	313
#define	TYPE_IDENTIFIER	314
#define	IDENTIFIER_t	315
#define	IMPLICIT	316
#define	IMPORTS	317
#define	INCLUDES	318
#define	INSTANCE	319
#define	INTEGER_t	320
#define	INTERSECTION	321
#define	ISO646String	322
#define	MACRO	323
#define	MAX_t	324
#define	MIN_t	325
#define	MINUS_INFINITY	326
#define	NOTATION	327
#define	NULL_VALUE	328
#define	NULL_TYPE	329
#define	NumericString	330
#define	OBJECT	331
#define	OCTET	332
#define	OF_t	333
#define	OPTIONAL_t	334
#define	PDV	335
#define	PLUS_INFINITY	336
#define	PRESENT	337
#define	PrintableString	338
#define	PRIVATE	339
#define	REAL	340
#define	SEQUENCE	341
#define	SET	342
#define	SIZE_t	343
#define	STRING	344
#define	SYNTAX	345
#define	T61String	346
#define	TAGS	347
#define	TeletexString	348
#define	TRUE_t	349
#define	TYPE_t	350
#define	UNION	351
#define	UNIQUE	352
#define	UNIVERSAL	353
#define	UniversalString	354
#define	VideotexString	355
#define	VisibleString	356
#define	GeneralizedTime	357
#define	UTCTime	358
#define	VALUE	359
#define	WITH	360
#define	string_t	361
#define	identifier_t	362
#define	number_t	363
#define	empty_t	364
#define	type_t	365
#define	value_t	366
#define	OBJECT_TYPE	367
#define	TRAP_TYPE	368
#define	ACCESS	369
#define	STATUS	370
#define	read_only_t	371
#define	read_write_t	372
#define	write_only_t	373
#define	not_accessible_t	374
#define	mandatory_t	375
#define	optional_t	376
#define	obsolete_t	377
#define	deprecated_t	378
#define	DESCRIPTION_t	379
#define	REFERENCE_t	380
#define	INDEX_t	381
#define	DEFVAL_t	382
#define	ENTERPRISE	383
#define	VARIABLES	384
#define	ObjectDescriptor_t	385

#line 3 "asn_grammar.y"


/*
 * asn_grammar.y
 *
 * ASN grammar file
 *
 * ASN.1 compiler to produce C++ classes.
 *
 * Copyright (c) 1997-1999 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is ASN Parser.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Portions of this code were written with the assisance of funding from
 * Vovida Networks, Inc. http://www.vovida.com.
 *
 * Portions are Copyright (C) 1993 Free Software Foundation, Inc.
 * All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 *
 * $Log: asn_grammar.y,v $
 * Revision 1.13  2004/04/03 08:22:23  csoutheren
 * Remove pseudo-RTTI and replaced with real RTTI
 *
 * Revision 1.12  2001/10/02 00:56:04  robertj
 * Fixed problem with autonumering enumerated types.
 *
 * Revision 1.11  2001/01/16 14:00:17  craigs
 * Changed MIN and MAX tokens to avoid namespace conflicts under BeOS
 *
 * Revision 1.10  2000/05/08 08:55:44  robertj
 * Fixed production error for ValueSet, thanks Huang-Ming Huang
 *
 * Revision 1.9  2000/01/19 12:33:07  robertj
 * Fixed parsing of OID's in IMPORTS section.
 *
 * Revision 1.8  2000/01/19 03:38:12  robertj
 * Fixed support for parsing multiple IMPORTS
 *
 * Revision 1.7  1999/07/22 06:48:54  robertj
 * Added comparison operation to base ASN classes and compiled ASN code.
 * Added support for ANY type in ASN parser.
 *
 * Revision 1.6  1999/06/09 06:58:08  robertj
 * Adjusted heading comments.
 *
 * Revision 1.5  1999/06/07 01:56:25  robertj
 * Added header comment on license.
 *
 * Revision 1.4  1999/06/06 05:30:28  robertj
 * Support for parameterised types and type-dentifier types.
 * Added ability to output multiple .cxx files.
 *
 * Revision 1.3  1998/12/14 06:47:55  robertj
 * New memory check code support.
 *
 * Revision 1.2  1998/05/21 04:21:46  robertj
 * Implementing more of the ASN spec.
 *
 * Revision 1.1  1997/12/13 09:17:47  robertj
 * Initial revision
 *
 */

#include <ptlib.h>

#undef malloc
#undef calloc
#undef realloc
#undef free

#include "main.h"

extern int yylex();

extern int ReferenceTokenContext;
extern int IdentifierTokenContext;
extern int BraceTokenContext;
extern int NullTokenContext;
extern int InMacroContext;
extern int HasObjectTypeMacro;
extern int InMIBContext;
extern TypesList * CurrentImportList;

static int UnnamedFieldCount = 1;
static PStringList * DummyParameters;

static PString * ConcatNames(PString * s1, char c, PString * s2)
{
  *s1 += c;
  *s1 += *s2;
  delete s2;
  return s1;
}

#ifdef _MSC_VER
#pragma warning(disable:4701)
#endif


#line 403 "asn_grammar.y"
typedef union {
  PInt64	          ival;
  PString	        * sval;
  PStringList	        * slst;
  TypeBase	        * tval;
  TypesList	        * tlst;
  ValueBase	        * vval;
  ValuesList            * vlst;
  NamedNumber	        * nval;
  NamedNumberList       * nlst;
  Constraint            * cons;
  ConstraintElementList * elst;
  ConstraintElementBase * elmt;
  struct {
    Tag::Type tagClass;
    unsigned tagNumber;
  } tagv;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		852
#define	YYFLAG		-32768
#define	YYNTBASE	149

#define YYTRANSLATE(x) ((unsigned)(x) <= 385 ? yytranslate[x] : 390)

static const short yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,   141,     2,     2,     2,     2,     2,     2,   133,
   134,     2,     2,   136,   148,   137,     2,   146,     2,     2,
     2,     2,     2,     2,     2,     2,     2,   142,   135,   140,
     2,   147,     2,   145,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
   138,     2,   139,   144,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,   131,   143,   132,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
    56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
    66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
    76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
    86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
   106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
   116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
   126,   127,   128,   129,   130
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,    11,    15,    16,    18,    21,    23,    25,    27,
    32,    35,    38,    41,    42,    46,    47,    51,    52,    54,
    55,    59,    60,    62,    63,    65,    68,    69,    74,    75,
    79,    81,    83,    84,    86,    88,    90,    94,    96,    98,
   100,   103,   105,   107,   109,   111,   113,   115,   117,   119,
   121,   123,   124,   130,   134,   136,   138,   140,   142,   144,
   146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
   166,   168,   170,   172,   174,   176,   178,   180,   182,   184,
   186,   188,   190,   192,   194,   198,   201,   207,   209,   213,
   218,   223,   225,   227,   229,   231,   233,   235,   237,   239,
   241,   243,   245,   247,   249,   251,   253,   256,   261,   263,
   267,   273,   275,   279,   284,   287,   289,   292,   297,   299,
   305,   313,   315,   319,   321,   323,   325,   327,   332,   336,
   338,   343,   345,   349,   352,   355,   357,   362,   366,   371,
   373,   377,   383,   387,   389,   393,   395,   398,   399,   404,
   408,   412,   417,   421,   425,   428,   432,   436,   441,   443,
   445,   447,   449,   451,   452,   456,   458,   460,   462,   466,
   468,   470,   472,   474,   477,   480,   482,   487,   492,   497,
   502,   507,   509,   511,   514,   515,   517,   519,   523,   525,
   531,   537,   544,   546,   549,   551,   555,   557,   561,   563,
   566,   569,   571,   573,   575,   577,   579,   581,   585,   587,
   589,   591,   593,   595,   597,   602,   604,   607,   609,   612,
   614,   616,   618,   620,   623,   626,   628,   630,   632,   634,
   637,   641,   645,   649,   657,   659,   663,   666,   670,   672,
   674,   676,   677,   679,   681,   687,   688,   690,   694,   696,
   700,   702,   704,   706,   713,   717,   719,   722,   726,   730,
   732,   736,   741,   746,   748,   750,   752,   754,   756,   758,
   762,   764,   766,   772,   776,   778,   780,   782,   784,   786,
   788,   790,   792,   795,   797,   800,   801,   806,   808,   809,
   811,   814,   815,   819,   823,   825,   828,   829,   833,   837,
   839,   842,   843,   847,   849,   852,   853,   857,   858,   862,
   865,   868,   870,   872,   874,   878,   880,   882,   884,   886,
   888,   890,   892,   894,   896,   898,   900,   902,   904,   906,
   908,   910,   912,   914,   916,   918,   920,   922,   924,   926,
   928,   930,   932,   936,   939,   941,   943,   947,   950,   954,
   956,   958,   960,   962,   964,   966,   968,   970,   972,   976,
   980,   982,   984,   986,   988,   990,   992,   994,   996,   998,
   999,  1005,  1011,  1017,  1022,  1028,  1034,  1038,  1042,  1044,
  1048,  1050,  1052,  1054,  1057,  1059,  1061,  1065,  1069,  1071,
  1073,  1075,  1077,  1079,  1080,  1086,  1088,  1090,  1092,  1094,
  1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
  1116,  1120,  1121,  1126,  1128,  1131,  1133,  1135,  1140,  1142,
  1144,  1146,  1148,  1150,  1152,  1154,  1158,  1161,  1163,  1167,
  1169,  1171,  1173,  1175,  1177,  1179,  1181,  1185,  1187,  1191,
  1193,  1195,  1205,  1211,  1215,  1217,  1219,  1221,  1223,  1225,
  1227,  1231,  1234,  1236,  1240,  1243,  1245,  1248,  1250,  1252,
  1256,  1261,  1262,  1267,  1269,  1273,  1276,  1281,  1286,  1288,
  1292,  1294,  1297,  1299,  1301,  1303,  1305,  1308,  1310,  1312,
  1314,  1316,  1318,  1324,  1329,  1335,  1341,  1345,  1347,  1350,
  1352,  1354,  1358,  1363,  1364,  1365,  1382,  1384,  1386,  1388,
  1390,  1392,  1394,  1396,  1398,  1401,  1402,  1405,  1406,  1411,
  1412,  1414,  1418,  1420,  1422,  1427,  1428,  1429,  1440,  1445,
  1446,  1448,  1452,  1454,  1456,  1458,  1460,  1462,  1466,  1468,
  1472,  1477,  1482,  1484
};

static const short yyrhs[] = {    -1,
     7,   151,    46,   155,    31,    33,   150,   156,    48,     0,
   131,   152,   132,     0,     0,   153,     0,   153,   152,     0,
     3,     0,    17,     0,   154,     0,     3,   133,    17,   134,
     0,    51,    92,     0,    61,    92,     0,    32,    92,     0,
     0,   157,   159,   170,     0,     0,    52,   158,   135,     0,
     0,   168,     0,     0,    62,   160,   135,     0,     0,   161,
     0,     0,   162,     0,   161,   162,     0,     0,   168,    55,
   163,   164,     0,     0,     7,   165,   166,     0,   167,     0,
   327,     0,     0,   326,     0,     6,     0,   169,     0,   169,
   136,   168,     0,   385,     0,   386,     0,   171,     0,   170,
   171,     0,   174,     0,   321,     0,   172,     0,   262,     0,
   263,     0,   264,     0,   304,     0,   355,     0,   370,     0,
   381,     0,     0,     8,   175,   173,    31,   354,     0,     8,
    31,   175,     0,   223,     0,   177,     0,   176,     0,   180,
     0,   183,     0,   184,     0,   187,     0,   192,     0,   193,
     0,   197,     0,   198,     0,   199,     0,   200,     0,   201,
     0,   202,     0,   203,     0,   204,     0,   205,     0,   206,
     0,   211,     0,   212,     0,   213,     0,   214,     0,   178,
     0,   219,     0,   218,     0,   220,     0,   179,     0,     8,
     0,   316,     0,     7,   137,     8,     0,    34,    89,     0,
    34,    89,   131,   181,   132,     0,   182,     0,   181,   136,
   182,     0,     3,   133,    17,   134,     0,     3,   133,   325,
   134,     0,    36,     0,   185,     0,   186,     0,    35,     0,
    56,     0,    57,     0,    58,     0,    67,     0,    75,     0,
    83,     0,    93,     0,    91,     0,    99,     0,   100,     0,
   101,     0,    38,    89,     0,    39,   131,   188,   132,     0,
   189,     0,   189,   136,   190,     0,   189,   136,   190,   136,
   189,     0,   191,     0,   189,   136,   191,     0,   137,   137,
   137,   227,     0,     3,   175,     0,   175,     0,    47,    80,
     0,    49,   131,   194,   132,     0,   195,     0,   195,   136,
   137,   137,   137,     0,   195,   136,   137,   137,   137,   136,
   195,     0,   196,     0,   195,   136,   196,     0,     3,     0,
   388,     0,    53,     0,    29,     0,    29,    45,    37,     3,
     0,    64,    78,   266,     0,    65,     0,    65,   131,   387,
   132,     0,    74,     0,   266,   137,   298,     0,    76,    60,
     0,    77,    89,     0,    85,     0,    86,   131,   207,   132,
     0,    86,   131,   132,     0,    86,   131,   190,   132,     0,
   208,     0,   208,   136,   190,     0,   208,   136,   190,   136,
   208,     0,   190,   136,   208,     0,   209,     0,   208,   136,
   209,     0,   191,     0,   191,    79,     0,     0,   191,    44,
   210,   323,     0,    42,    78,   175,     0,    86,    78,   175,
     0,    87,   131,   207,   132,     0,    87,   131,   132,     0,
    87,    78,   175,     0,   215,   175,     0,   215,    61,   175,
     0,   215,    51,   175,     0,   138,   217,   216,   139,     0,
    17,     0,   325,     0,    98,     0,    30,     0,    84,     0,
     0,     3,   140,   175,     0,   102,     0,   103,     0,   130,
     0,   221,   137,   298,     0,   292,     0,   222,     0,   295,
     0,   297,     0,   292,   318,     0,   175,   225,     0,   224,
     0,    87,   225,    78,   175,     0,    87,   246,    78,   175,
     0,    86,   225,    78,   175,     0,    86,   246,    78,   175,
     0,   133,   226,   227,   134,     0,   229,     0,   252,     0,
   141,   228,     0,     0,   389,     0,   325,     0,   175,   142,
   323,     0,   230,     0,   230,   136,   137,   137,   137,     0,
   137,   137,   137,   136,   230,     0,   230,   136,   137,   137,
   137,   230,     0,   231,     0,    28,   234,     0,   232,     0,
   231,   235,   232,     0,   233,     0,   232,   236,   233,     0,
   237,     0,   237,   234,     0,    50,   237,     0,   143,     0,
    96,     0,   144,     0,    66,     0,   238,     0,   303,     0,
   133,   230,   134,     0,   323,     0,   245,     0,   239,     0,
   244,     0,   246,     0,   247,     0,   240,   137,   137,   241,
     0,   242,     0,   242,   140,     0,   243,     0,   140,   243,
     0,   323,     0,    70,     0,   323,     0,    69,     0,    55,
   225,     0,    63,   175,     0,   223,     0,   176,     0,   178,
     0,   219,     0,    88,   225,     0,   105,    41,   225,     0,
   105,    42,   248,     0,   131,   249,   132,     0,   131,   137,
   137,   137,   136,   249,   132,     0,   250,     0,   250,   136,
   249,     0,     3,   251,     0,     3,   225,   251,     0,    82,
     0,    26,     0,    79,     0,     0,   253,     0,   257,     0,
    43,    37,   131,   254,   132,     0,     0,   255,     0,   256,
   136,   255,     0,   256,     0,   315,   142,   320,     0,   320,
     0,   301,     0,   258,     0,   131,   295,   132,   131,   259,
   132,     0,   259,   136,   260,     0,   260,     0,   145,   261,
     0,   145,   137,   261,     0,   261,   137,     3,     0,     3,
     0,     9,    31,   265,     0,    15,   266,    31,   300,     0,
    16,   266,    31,   301,     0,   266,     0,   269,     0,   294,
     0,   267,     0,     9,     0,   268,     0,     7,   137,     9,
     0,    59,     0,    27,     0,    40,   131,   270,   132,   285,
     0,   270,   136,   271,     0,   271,     0,   272,     0,   274,
     0,   277,     0,   278,     0,   280,     0,   281,     0,   283,
     0,    10,   273,     0,    79,     0,    44,   175,     0,     0,
    11,   175,   275,   276,     0,    97,     0,     0,    79,     0,
    44,   323,     0,     0,    11,   298,   276,     0,    12,   175,
   279,     0,    79,     0,    44,   354,     0,     0,    12,   298,
   279,     0,    13,   266,   282,     0,    79,     0,    44,   300,
     0,     0,    14,   266,   284,     0,    79,     0,    44,   301,
     0,     0,   105,    90,   286,     0,     0,   131,   287,   132,
     0,   131,   132,     0,   287,   288,     0,   288,     0,   290,
     0,   289,     0,   138,   287,   139,     0,   291,     0,   299,
     0,    34,     0,    36,     0,    38,     0,    39,     0,    47,
     0,    48,     0,    49,     0,    53,     0,    54,     0,    64,
     0,    17,     0,    66,     0,    71,     0,    74,     0,    76,
     0,    77,     0,    81,     0,    85,     0,    86,     0,    87,
     0,    94,     0,    96,     0,   136,     0,   293,     0,    15,
     0,     7,   137,    15,     0,   266,   318,     0,   296,     0,
    16,     0,     7,   137,    16,     0,   295,   318,     0,   298,
   137,   299,     0,   299,     0,    10,     0,    11,     0,    12,
     0,    13,     0,    14,     0,   292,     0,   302,     0,   222,
     0,   131,   230,   132,     0,   221,   137,   298,     0,   300,
     0,   295,     0,   297,     0,   305,     0,   307,     0,   308,
     0,   309,     0,   310,     0,   311,     0,     0,     8,   312,
   306,    31,   175,     0,     3,   312,   175,    31,   323,     0,
     8,   312,   175,    31,   354,     0,     9,   312,    31,   265,
     0,    15,   312,   266,    31,   300,     0,    16,   312,   266,
    31,   301,     0,   131,   313,   132,     0,   313,   136,   314,
     0,   314,     0,   315,   142,   385,     0,   385,     0,   175,
     0,   266,     0,   317,   318,     0,   179,     0,     8,     0,
   131,   319,   132,     0,   319,   136,   320,     0,   320,     0,
   175,     0,   323,     0,   354,     0,   266,     0,     0,     3,
   175,   322,    31,   323,     0,   324,     0,   351,     0,   333,
     0,   335,     0,   336,     0,   343,     0,   389,     0,   344,
     0,   327,     0,   332,     0,   345,     0,   348,     0,   326,
     0,     3,     0,   352,     0,     7,   137,     3,     0,     0,
    25,   328,   329,   132,     0,   330,     0,   330,   329,     0,
     5,     0,    17,     0,     5,   133,   331,   134,     0,    17,
     0,   326,     0,     5,     0,    19,     0,    21,     0,    20,
     0,    22,     0,    24,   334,   132,     0,    24,   132,     0,
     4,     0,   334,   136,     4,     0,    94,     0,    54,     0,
   337,     0,    18,     0,   338,     0,   341,     0,   342,     0,
    23,   339,   132,     0,   340,     0,   339,   136,   340,     0,
    18,     0,   325,     0,    23,    17,   136,    17,   136,    17,
   136,    17,   132,     0,    23,    17,   136,    17,   132,     0,
     3,   142,   323,     0,    73,     0,   346,     0,   347,     0,
   146,     0,    81,     0,    71,     0,   131,   349,   132,     0,
   131,   132,     0,   350,     0,   349,   136,   350,     0,     3,
   323,     0,   325,     0,   353,   318,     0,   326,     0,     3,
     0,   131,   229,   132,     0,     8,    68,    31,   356,     0,
     0,    33,   357,   358,    48,     0,     8,     0,     8,   137,
     8,     0,   359,   360,     0,    95,    72,    31,   361,     0,
   104,    72,    31,   361,     0,   362,     0,   362,   143,   361,
     0,   363,     0,   363,   362,     0,   364,     0,   365,     0,
    18,     0,     8,     0,     8,    31,     0,   106,     0,   107,
     0,   108,     0,   109,     0,   110,     0,   110,   133,    95,
     8,   134,     0,   111,   133,   175,   134,     0,   111,   133,
     3,   175,   134,     0,   111,   133,   104,   175,   134,     0,
   140,   366,   147,     0,   367,     0,   366,   367,     0,   368,
     0,   369,     0,     8,    31,   175,     0,     3,   175,    31,
   323,     0,     0,     0,     3,   112,   371,    90,   175,   114,
   373,   115,   374,   375,   376,   377,   380,   372,    31,   323,
     0,   116,     0,   117,     0,   118,     0,   119,     0,   120,
     0,   121,     0,   122,     0,   123,     0,   124,    18,     0,
     0,   125,    18,     0,     0,   126,   131,   378,   132,     0,
     0,   379,     0,   378,   136,   379,     0,     3,     0,     8,
     0,   127,   131,   323,   132,     0,     0,     0,     3,   113,
   382,   128,   323,   383,   375,   376,    31,   323,     0,   129,
   131,   384,   132,     0,     0,   323,     0,   384,   136,   323,
     0,     8,     0,     3,     0,     9,     0,    15,     0,    16,
     0,   385,   131,   132,     0,   388,     0,   387,   136,   388,
     0,     3,   133,   389,   134,     0,     3,   133,   325,   134,
     0,    17,     0,   148,    17,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   426,   431,   435,   439,   446,   451,   459,   460,   464,   468,
   476,   480,   484,   488,   498,   499,   504,   505,   510,   514,
   522,   523,   528,   529,   533,   534,   539,   545,   559,   565,
   573,   574,   575,   582,   586,   595,   600,   609,   613,   619,
   620,   625,   626,   627,   628,   629,   630,   631,   633,   634,
   635,   640,   647,   660,   669,   670,   671,   676,   677,   678,
   679,   680,   681,   682,   683,   684,   686,   687,   688,   689,
   690,   691,   692,   693,   694,   695,   696,   701,   702,   703,
   704,   712,   716,   722,   728,   737,   741,   749,   754,   761,
   765,   774,   782,   783,   787,   791,   795,   799,   803,   807,
   811,   815,   819,   823,   827,   831,   839,   847,   854,   858,
   862,   869,   874,   882,   887,   892,   902,   910,   917,   921,
   925,   932,   937,   948,   952,   957,   965,   969,   977,   982,
   986,   994,  1002,  1010,  1017,  1025,  1033,  1037,  1041,  1048,
  1052,  1056,  1060,  1067,  1072,  1079,  1080,  1084,  1089,  1093,
  1101,  1109,  1113,  1121,  1129,  1134,  1139,  1147,  1155,  1156,
  1166,  1170,  1174,  1178,  1186,  1194,  1198,  1202,  1210,  1221,
  1222,  1223,  1225,  1230,  1238,  1242,  1246,  1250,  1254,  1258,
  1265,  1272,  1273,  1278,  1282,  1290,  1294,  1295,  1305,  1309,
  1313,  1317,  1325,  1326,  1335,  1340,  1347,  1352,  1359,  1360,
  1367,  1374,  1375,  1379,  1380,  1384,  1385,  1386,  1394,  1398,
  1402,  1403,  1404,  1406,  1410,  1417,  1418,  1422,  1423,  1430,
  1431,  1438,  1439,  1446,  1453,  1460,  1461,  1462,  1463,  1468,
  1476,  1480,  1487,  1491,  1498,  1503,  1511,  1515,  1522,  1526,
  1530,  1534,  1542,  1543,  1547,  1554,  1558,  1565,  1570,  1578,
  1582,  1587,  1588,  1592,  1597,  1598,  1602,  1603,  1607,  1608,
  1615,  1620,  1625,  1631,  1633,  1634,  1638,  1639,  1640,  1645,
  1652,  1656,  1664,  1668,  1669,  1673,  1674,  1675,  1676,  1677,
  1678,  1679,  1683,  1688,  1689,  1690,  1694,  1699,  1700,  1704,
  1705,  1706,  1710,  1715,  1720,  1721,  1722,  1726,  1731,  1736,
  1737,  1738,  1742,  1747,  1748,  1749,  1753,  1754,  1758,  1759,
  1763,  1764,  1768,  1769,  1773,  1777,  1778,  1783,  1784,  1785,
  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1795,  1796,
  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,  1806,
  1811,  1812,  1817,  1823,  1829,  1831,  1836,  1842,  1847,  1851,
  1856,  1857,  1858,  1859,  1860,  1865,  1871,  1873,  1923,  1929,
  1934,  1936,  1941,  1956,  1957,  1958,  1959,  1960,  1961,  1965,
  1969,  1979,  1984,  1989,  1994,  1999,  2004,  2011,  2016,  2024,
  2028,  2032,  2034,  2040,  2047,  2048,  2053,  2060,  2065,  2073,
  2074,  2076,  2078,  2092,  2098,  2110,  2111,  2116,  2117,  2118,
  2119,  2124,  2128,  2132,  2133,  2134,  2135,  2146,  2150,  2154,
  2159,  2168,  2172,  2187,  2192,  2200,  2201,  2205,  2213,  2217,
  2218,  2223,  2227,  2234,  2238,  2242,  2246,  2254,  2258,  2267,
  2271,  2279,  2286,  2290,  2291,  2292,  2296,  2303,  2308,  2315,
  2316,  2323,  2332,  2342,  2351,  2359,  2360,  2364,  2374,  2378,
  2386,  2390,  2397,  2402,  2409,  2451,  2466,  2471,  2472,  2480,
  2487,  2494,  2498,  2502,  2504,  2509,  2513,  2517,  2539,  2540,
  2544,  2545,  2549,  2550,  2554,  2556,  2558,  2560,  2561,  2562,
  2563,  2564,  2565,  2566,  2567,  2568,  2572,  2576,  2577,  2581,
  2582,  2586,  2591,  2599,  2603,  2613,  2622,  2626,  2630,  2634,
  2641,  2645,  2649,  2653,  2660,  2664,  2671,  2675,  2682,  2686,
  2693,  2698,  2705,  2706,  2710,  2714,  2721,  2726,  2739,  2743,
  2750,  2755,  2788,  2789,  2790,  2791,  2792,  2796,  2804,  2809,
  2816,  2820,  2829,  2830
};

static const char * const yytname[] = {   "$","error","$undefined.","IDENTIFIER",
"BIT_IDENTIFIER","OID_IDENTIFIER","IMPORT_IDENTIFIER","MODULEREFERENCE","TYPEREFERENCE",
"OBJECTCLASSREFERENCE","TYPEFIELDREFERENCE","VALUEFIELDREFERENCE","VALUESETFIELDREFERENCE",
"OBJECTFIELDREFERENCE","OBJECTSETFIELDREFERENCE","OBJECTREFERENCE","OBJECTSETREFERENCE",
"INTEGER","CSTRING","OS_BSTRING","BS_BSTRING","OS_HSTRING","BS_HSTRING","STRING_BRACE",
"BITSTRING_BRACE","OID_BRACE","ABSENT","ABSTRACT_SYNTAX","ALL","ANY","APPLICATION",
"ASSIGNMENT","AUTOMATIC","BEGIN_t","BIT","BMPString","BOOLEAN_t","BY","CHARACTER",
"CHOICE","CLASS","COMPONENT","COMPONENTS","CONSTRAINED","DEFAULT","DEFINED",
"DEFINITIONS","EMBEDDED","END","ENUMERATED","EXCEPT","EXPLICIT","EXPORTS","EXTERNAL",
"FALSE_t","FROM","GeneralString","GraphicString","IA5String","TYPE_IDENTIFIER",
"IDENTIFIER_t","IMPLICIT","IMPORTS","INCLUDES","INSTANCE","INTEGER_t","INTERSECTION",
"ISO646String","MACRO","MAX_t","MIN_t","MINUS_INFINITY","NOTATION","NULL_VALUE",
"NULL_TYPE","NumericString","OBJECT","OCTET","OF_t","OPTIONAL_t","PDV","PLUS_INFINITY",
"PRESENT","PrintableString","PRIVATE","REAL","SEQUENCE","SET","SIZE_t","STRING",
"SYNTAX","T61String","TAGS","TeletexString","TRUE_t","TYPE_t","UNION","UNIQUE",
"UNIVERSAL","UniversalString","VideotexString","VisibleString","GeneralizedTime",
"UTCTime","VALUE","WITH","string_t","identifier_t","number_t","empty_t","type_t",
"value_t","OBJECT_TYPE","TRAP_TYPE","ACCESS","STATUS","read_only_t","read_write_t",
"write_only_t","not_accessible_t","mandatory_t","optional_t","obsolete_t","deprecated_t",
"DESCRIPTION_t","REFERENCE_t","INDEX_t","DEFVAL_t","ENTERPRISE","VARIABLES",
"ObjectDescriptor_t","'{'","'}'","'('","')'","';'","','","'.'","'['","']'","'<'",
"'!'","':'","'|'","'^'","'@'","'0'","'>'","'-'","ModuleDefinition","@1","DefinitiveIdentifier",
"DefinitiveObjIdComponentList","DefinitiveObjIdComponent","DefinitiveNameAndNumberForm",
"TagDefault","ModuleBody","Exports","SymbolsExported","Imports","SymbolsImported",
"SymbolsFromModuleList","SymbolsFromModule","@2","GlobalModuleReference","@3",
"AssignedIdentifier","DefinedValue_Import","SymbolList","Symbol","AssignmentList",
"Assignment","ValueSetTypeAssignment","@4","TypeAssignment","Type","BuiltinType",
"ReferencedType","DefinedType","ExternalTypeReference","BitStringType","NamedBitList",
"NamedBit","BooleanType","CharacterStringType","RestrictedCharacterStringType",
"UnrestrictedCharacterStringType","ChoiceType","AlternativeTypeLists","AlternativeTypeList",
"ExtensionAndException","NamedType","EmbeddedPDVType","EnumeratedType","Enumerations",
"Enumeration","EnumerationItem","ExternalType","AnyType","InstanceOfType","IntegerType",
"NullType","ObjectClassFieldType","ObjectIdentifierType","OctetStringType","RealType",
"SequenceType","ComponentTypeLists","ComponentTypeList","ComponentType","@5",
"SequenceOfType","SetType","SetOfType","TaggedType","Tag","ClassNumber","Class",
"SelectionType","UsefulType","TypeFromObject","ReferencedObjects","ParameterizedObject",
"ConstrainedType","TypeWithConstraint","Constraint","ConstraintSpec","ExceptionSpec",
"ExceptionIdentification","ElementSetSpecs","ElementSetSpec","Unions","Intersections",
"IntersectionElements","Exclusions","UnionMark","IntersectionMark","Elements",
"SubtypeElements","ValueRange","LowerEndpoint","UpperEndpoint","LowerEndValue",
"UpperEndValue","PermittedAlphabet","ContainedSubtype","SizeConstraint","InnerTypeConstraints",
"MultipleTypeConstraints","TypeConstraints","NamedConstraint","PresenceConstraint",
"GeneralConstraint","UserDefinedConstraint","UserDefinedConstraintParameterList",
"UserDefinedConstraintParameters","UserDefinedConstraintParameter","TableConstraint",
"ComponentRelationConstraint","AtNotations","AtNotation","ComponentIdList","ObjectClassAssignment",
"ObjectAssignment","ObjectSetAssignment","ObjectClass","DefinedObjectClass",
"ExternalObjectClassReference","UsefulObjectClassReference","ObjectClassDefn",
"FieldSpecs","FieldSpec","TypeFieldSpec","TypeOptionalitySpec","FixedTypeValueFieldSpec",
"Unique","ValueOptionalitySpec","VariableTypeValueFieldSpec","FixedTypeValueSetFieldSpec",
"ValueSetOptionalitySpec","VariableTypeValueSetFieldSpec","ObjectFieldSpec",
"ObjectOptionalitySpec","ObjectSetFieldSpec","ObjectSetOptionalitySpec","WithSyntaxSpec",
"SyntaxList","TokenOrGroupSpecs","TokenOrGroupSpec","OptionalGroup","RequiredToken",
"Literal","DefinedObject","ExternalObjectReference","ParameterizedObjectClass",
"DefinedObjectSet","ExternalObjectSetReference","ParameterizedObjectSet","FieldName",
"PrimitiveFieldName","Object","ObjectSet","ObjectFromObject","ObjectSetElements",
"ParameterizedAssignment","ParameterizedTypeAssignment","@6","ParameterizedValueAssignment",
"ParameterizedValueSetTypeAssignment","ParameterizedObjectClassAssignment","ParameterizedObjectAssignment",
"ParameterizedObjectSetAssignment","ParameterList","Parameters","Parameter",
"Governor","ParameterizedType","SimpleDefinedType","ActualParameterList","ActualParameters",
"ActualParameter","ValueAssignment","@7","Value","BuiltinValue","DefinedValue",
"ExternalValueReference","ObjectIdentifierValue","@8","ObjIdComponentList","ObjIdComponent",
"NumberForm","OctetStringValue","BitStringValue","BitIdentifierList","BooleanValue",
"CharacterStringValue","RestrictedCharacterStringValue","CharacterStringList",
"CharSyms","CharsDefn","Quadruple","Tuple","ChoiceValue","NullValue","RealValue",
"NumericRealValue","SpecialRealValue","SequenceValue","ComponentValueList","NamedValue",
"ReferencedValue","ParameterizedValue","SimpleDefinedValue","ValueSet","MacroDefinition",
"MacroSubstance","@9","MacroBody","TypeProduction","ValueProduction","MacroAlternativeList",
"MacroAlternative","SymbolElement","SymbolDefn","EmbeddedDefinitions","EmbeddedDefinitionList",
"EmbeddedDefinition","LocalTypeAssignment","LocalValueAssignment","ObjectTypeDefinition",
"@10","@11","ObjectTypeAccess","ObjectTypeStatus","MibDescrPart","MibReferPart",
"MibIndexPart","MibIndexTypes","MibIndexType","MibDefValPart","TrapTypeDefinition",
"@12","MibVarPart","MibVarTypes","Reference","ParameterizedReference","NamedNumberList",
"NamedNumber","SignedNumber",""
};
#endif

static const short yyr1[] = {     0,
   150,   149,   151,   151,   152,   152,   153,   153,   153,   154,
   155,   155,   155,   155,   156,   156,   157,   157,   158,   158,
   159,   159,   160,   160,   161,   161,   163,   162,   165,   164,
   166,   166,   166,   167,   167,   168,   168,   169,   169,   170,
   170,   171,   171,   171,   171,   171,   171,   171,   171,   171,
   171,   173,   172,   174,   175,   175,   175,   176,   176,   176,
   176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
   176,   176,   176,   176,   176,   176,   176,   177,   177,   177,
   177,   178,   178,   178,   179,   180,   180,   181,   181,   182,
   182,   183,   184,   184,   185,   185,   185,   185,   185,   185,
   185,   185,   185,   185,   185,   185,   186,   187,   188,   188,
   188,   189,   189,   190,   191,   191,   192,   193,   194,   194,
   194,   195,   195,   196,   196,   197,   198,   198,   199,   200,
   200,   201,   202,   203,   204,   205,   206,   206,   206,   207,
   207,   207,   207,   208,   208,   209,   209,   210,   209,   209,
   211,   212,   212,   213,   214,   214,   214,   215,   216,   216,
   217,   217,   217,   217,   218,   219,   219,   219,   220,   221,
   221,   221,   221,   222,   223,   223,   224,   224,   224,   224,
   225,   226,   226,   227,   227,   228,   228,   228,   229,   229,
   229,   229,   230,   230,   231,   231,   232,   232,   233,   233,
   234,   235,   235,   236,   236,   237,   237,   237,   238,   238,
   238,   238,   238,   238,   239,   240,   240,   241,   241,   242,
   242,   243,   243,   244,   245,   245,   245,   245,   245,   246,
   247,   247,   248,   248,   249,   249,   250,   250,   251,   251,
   251,   251,   252,   252,   253,   254,   254,   255,   255,   256,
   256,   257,   257,   258,   259,   259,   260,   260,   261,   261,
   262,   263,   264,   265,   265,   265,   266,   266,   266,   267,
   268,   268,   269,   270,   270,   271,   271,   271,   271,   271,
   271,   271,   272,   273,   273,   273,   274,   275,   275,   276,
   276,   276,   277,   278,   279,   279,   279,   280,   281,   282,
   282,   282,   283,   284,   284,   284,   285,   285,   286,   286,
   287,   287,   288,   288,   289,   290,   290,   291,   291,   291,
   291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
   291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
   292,   292,   293,   294,   295,   295,   296,   297,   298,   298,
   299,   299,   299,   299,   299,   300,   300,   300,   301,   302,
   303,   303,   303,   304,   304,   304,   304,   304,   304,   306,
   305,   307,   308,   309,   310,   311,   312,   313,   313,   314,
   314,   315,   315,   316,   317,   317,   318,   319,   319,   320,
   320,   320,   320,   322,   321,   323,   323,   324,   324,   324,
   324,   324,   324,   324,   324,   324,   324,   325,   325,   325,
   326,   328,   327,   329,   329,   330,   330,   330,   331,   331,
   331,   332,   332,   333,   333,   333,   333,   334,   334,   335,
   335,   336,   337,   337,   337,   337,   338,   339,   339,   340,
   340,   341,   342,   343,   344,   345,   345,   346,   347,   347,
   348,   348,   349,   349,   350,   351,   352,   353,   353,   354,
   355,   357,   356,   356,   356,   358,   359,   360,   361,   361,
   362,   362,   363,   363,   364,   364,   364,   364,   364,   364,
   364,   364,   364,   364,   364,   364,   365,   366,   366,   367,
   367,   368,   369,   371,   372,   370,   373,   373,   373,   373,
   374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
   378,   378,   379,   379,   380,   380,   382,   381,   383,   383,
   384,   384,   385,   385,   385,   385,   385,   386,   387,   387,
   388,   388,   389,   389
};

static const short yyr2[] = {     0,
     0,     9,     3,     0,     1,     2,     1,     1,     1,     4,
     2,     2,     2,     0,     3,     0,     3,     0,     1,     0,
     3,     0,     1,     0,     1,     2,     0,     4,     0,     3,
     1,     1,     0,     1,     1,     1,     3,     1,     1,     1,
     2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     3,     2,     5,     1,     3,     4,
     4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     2,     4,     1,     3,
     5,     1,     3,     4,     2,     1,     2,     4,     1,     5,
     7,     1,     3,     1,     1,     1,     1,     4,     3,     1,
     4,     1,     3,     2,     2,     1,     4,     3,     4,     1,
     3,     5,     3,     1,     3,     1,     2,     0,     4,     3,
     3,     4,     3,     3,     2,     3,     3,     4,     1,     1,
     1,     1,     1,     0,     3,     1,     1,     1,     3,     1,
     1,     1,     1,     2,     2,     1,     4,     4,     4,     4,
     4,     1,     1,     2,     0,     1,     1,     3,     1,     5,
     5,     6,     1,     2,     1,     3,     1,     3,     1,     2,
     2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
     1,     1,     1,     1,     4,     1,     2,     1,     2,     1,
     1,     1,     1,     2,     2,     1,     1,     1,     1,     2,
     3,     3,     3,     7,     1,     3,     2,     3,     1,     1,
     1,     0,     1,     1,     5,     0,     1,     3,     1,     3,
     1,     1,     1,     6,     3,     1,     2,     3,     3,     1,
     3,     4,     4,     1,     1,     1,     1,     1,     1,     3,
     1,     1,     5,     3,     1,     1,     1,     1,     1,     1,
     1,     1,     2,     1,     2,     0,     4,     1,     0,     1,
     2,     0,     3,     3,     1,     2,     0,     3,     3,     1,
     2,     0,     3,     1,     2,     0,     3,     0,     3,     2,
     2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     3,     2,     1,     1,     3,     2,     3,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
     5,     5,     5,     4,     5,     5,     3,     3,     1,     3,
     1,     1,     1,     2,     1,     1,     3,     3,     1,     1,
     1,     1,     1,     0,     5,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
     3,     0,     4,     1,     2,     1,     1,     4,     1,     1,
     1,     1,     1,     1,     1,     3,     2,     1,     3,     1,
     1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
     1,     9,     5,     3,     1,     1,     1,     1,     1,     1,
     3,     2,     1,     3,     2,     1,     2,     1,     1,     3,
     4,     0,     4,     1,     3,     2,     4,     4,     1,     3,
     1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
     1,     1,     5,     4,     5,     5,     3,     1,     2,     1,
     1,     3,     4,     0,     0,    16,     1,     1,     1,     1,
     1,     1,     1,     1,     2,     0,     2,     0,     4,     0,
     1,     3,     1,     1,     4,     0,     0,    10,     4,     0,
     1,     3,     1,     1,     1,     1,     1,     3,     1,     3,
     4,     4,     1,     2
};

static const short yydefact[] = {     0,
     4,     0,     0,     7,     8,     0,     5,     9,    14,     0,
     3,     6,     0,     0,     0,     0,     0,    13,    11,    12,
     0,    10,     1,    18,    20,     0,    22,   524,   523,   525,
   526,   527,     0,    19,    36,    38,    39,     2,    24,     0,
    17,     0,     0,     0,    23,    25,     0,     0,     0,     0,
     0,     0,    15,    40,    44,    42,    45,    46,    47,    48,
   364,   365,   366,   367,   368,   369,    43,    49,    50,    51,
    37,   528,    21,    26,    27,     0,     0,    83,   268,   342,
   346,   272,   127,     0,    95,    92,     0,     0,     0,     0,
   126,    96,    97,    98,   271,     0,   130,    99,   132,   100,
     0,     0,   101,   136,     0,     0,   103,   102,   104,   105,
   106,   166,   167,   494,   517,   168,     0,   164,   394,    57,
    56,    78,    82,    58,    59,    60,    93,    94,    61,    62,
    63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
    73,    74,    75,    76,    77,     0,    80,    79,    81,     0,
   171,    55,   176,     0,   267,   269,   170,   341,   172,   345,
   173,     0,    84,     0,     0,     0,    52,   370,     0,     0,
     0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
    86,   107,     0,   117,     0,     0,     0,   134,   135,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   524,    83,   268,   342,   346,   382,   383,     0,   379,
     0,   381,   162,   163,   161,     0,   175,     0,     0,     0,
   155,     0,     0,     0,   174,   348,     0,   384,    54,     0,
     0,     0,     0,     0,   261,   264,   265,   266,     0,     0,
     0,     0,     0,     0,    29,    28,   165,    85,   270,   343,
   347,     0,     0,     0,   116,     0,   109,   112,   124,     0,
   119,   122,   125,   129,     0,     0,   529,   151,   230,     0,
   138,     0,     0,   146,     0,   140,   144,   409,     0,   533,
   433,   422,   424,   423,   425,     0,     0,   412,     0,     0,
   431,     0,     0,   221,   450,   445,   449,   430,     0,     0,
     0,     0,   448,     0,     0,   227,   228,   229,     0,   358,
   226,   185,   182,   189,   193,   195,   197,   199,   206,   211,
     0,   216,   212,   210,   213,   214,   183,   243,   244,   253,
   356,   362,   363,   361,   252,   357,   207,   209,   396,   456,
   408,   404,   405,   398,   399,   400,   432,   434,   435,   436,
   401,   403,   406,   446,   447,   407,   397,   410,     0,   402,
     0,     0,   154,   153,     0,     0,     0,     0,     0,     0,
   377,     0,     0,   409,     0,   159,     0,   160,     0,   157,
   156,   351,   352,   353,   354,   355,   169,   350,   133,     0,
   390,   393,     0,   389,   391,   392,     0,   464,   462,   461,
     0,     0,     0,     0,   344,   374,     0,     0,   262,     0,
     0,   263,     0,    33,   128,     0,     0,    88,   115,   108,
     0,     0,   118,     0,   131,     0,     0,     0,   139,     0,
   148,   147,   137,     0,     0,     0,     0,   440,   441,     0,
   438,   428,   427,     0,     0,     0,   194,     0,   224,   225,
     0,     0,   409,     0,   452,     0,   362,     0,   453,     0,
     0,   534,     0,     0,     0,     0,   203,   202,     0,   205,
   204,     0,   200,     0,   217,   457,   179,   180,   152,   177,
   178,     0,   409,   520,   378,   380,     0,   158,   395,     0,
     0,   387,     0,   372,     0,     0,     0,    53,   373,   371,
   286,     0,     0,     0,     0,     0,   275,   276,   277,   278,
   279,   280,   281,   282,     0,     0,   375,   376,    35,    30,
    31,    34,    32,     0,    87,     0,   110,   113,     0,     0,
     0,   123,   530,   150,   185,   143,     0,   141,   145,   444,
   411,     0,   437,     0,   426,     0,   416,   417,     0,   414,
   201,   246,   231,     0,   232,   455,     0,   359,     0,   451,
     0,   208,     0,   360,   409,     0,   184,   187,   186,   181,
     0,   196,   198,     0,     0,     0,   506,   349,   460,   388,
   465,     0,     0,     0,     0,   284,   283,   289,   292,   297,
   297,   302,   306,   308,     0,   360,     0,     0,    89,     0,
   532,   531,     0,   114,     0,   149,     0,     0,   439,   429,
     0,   413,   415,   390,     0,   247,   249,   393,     0,   251,
   242,     0,     0,   235,     0,   454,     0,     0,     0,   223,
     0,   215,   218,   222,   497,   498,   499,   500,     0,     0,
     0,   508,     0,   463,     0,   466,   285,   288,   292,     0,
   290,   293,     0,   295,   294,   298,     0,   300,   299,     0,
   304,   303,     0,   273,   274,    90,    91,   111,   120,   142,
   443,     0,   421,   419,   420,     0,   245,     0,     0,   240,
   241,   239,   242,   237,     0,   233,     0,     0,     0,   256,
   191,   188,   190,   219,     0,   521,     0,   505,     0,     0,
     0,     0,   287,   291,   296,   301,   305,     0,     0,     0,
     0,   418,   248,   250,   238,     0,   236,   260,     0,   257,
   254,     0,   192,   501,   502,   503,   504,   506,   519,     0,
   507,     0,   476,   475,   478,   479,   480,   481,   482,     0,
     0,   467,   469,   471,   473,   474,     0,     0,   307,   121,
     0,     0,   258,     0,   255,   508,   522,   518,   477,     0,
     0,     0,     0,     0,   488,   490,   491,     0,   472,   468,
   328,   318,   319,   320,   321,   322,   323,   324,   325,   326,
   327,   329,   330,   331,   332,   333,   334,   335,   336,   337,
   338,   339,   310,   340,     0,     0,   312,   314,   313,   316,
   317,     0,     0,     0,   259,   510,     0,     0,     0,     0,
     0,     0,   487,   489,   470,     0,   309,   311,   442,   234,
     0,   516,     0,     0,     0,   484,     0,   492,   315,     0,
     0,   495,   483,   485,   486,   493,   513,   514,     0,   511,
     0,     0,   509,     0,     0,     0,   512,   515,   496,     0,
     0,     0
};

static const short yydefgoto[] = {   850,
    24,     3,     6,     7,     8,    16,    26,    27,    33,    40,
    44,    45,    46,   177,   246,   414,   520,   521,    47,    35,
    53,    54,    55,   231,    56,   305,   120,   121,   122,   123,
   124,   417,   418,   125,   126,   127,   128,   129,   256,   257,
   273,   274,   130,   131,   260,   261,   262,   132,   133,   134,
   135,   136,   137,   138,   139,   140,   141,   275,   276,   277,
   537,   142,   143,   144,   145,   146,   377,   216,   147,   148,
   149,   150,   151,   152,   153,   217,   312,   465,   567,   491,
   314,   315,   316,   317,   447,   469,   472,   318,   319,   320,
   321,   632,   322,   633,   323,   324,   325,   326,   555,   623,
   624,   684,   327,   328,   615,   616,   617,   329,   330,   689,
   690,   720,    57,    58,    59,   235,   154,   155,   156,   237,
   506,   507,   508,   587,   509,   649,   652,   510,   511,   655,
   512,   513,   659,   514,   662,   664,   749,   796,   797,   798,
   799,   800,   157,   158,   238,   159,   160,   161,   387,   388,
   334,   335,   336,   337,    60,    61,   233,    62,    63,    64,
    65,    66,   162,   209,   210,   211,   163,   164,   226,   393,
   620,    67,   218,   338,   339,   340,   341,   342,   445,   549,
   550,   676,   343,   344,   444,   345,   346,   347,   348,   440,
   441,   349,   350,   351,   352,   353,   354,   355,   356,   458,
   459,   357,   358,   359,   396,    68,   400,   496,   583,   584,
   646,   742,   743,   744,   745,   746,   764,   765,   766,   767,
    69,   200,   842,   639,   728,   642,   700,   822,   839,   840,
   832,    70,   201,   577,   697,    36,    37,   266,   263,   360
};

static const short yypact[] = {    68,
   -19,   115,   112,    50,-32768,    57,   115,-32768,    27,   180,
-32768,-32768,   128,   133,   146,   252,   164,-32768,-32768,-32768,
   290,-32768,-32768,    61,   288,   297,   238,-32768,-32768,-32768,
-32768,-32768,   201,-32768,   211,   221,-32768,-32768,   288,   355,
-32768,   288,   222,   230,   288,-32768,   347,  2113,  2221,     5,
    56,    56,   355,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,   243,   270,   273,-32768,-32768,
-32768,-32768,   375,   372,-32768,-32768,   374,   348,   390,   353,
-32768,-32768,-32768,-32768,-32768,   398,   358,-32768,-32768,-32768,
   426,   401,-32768,-32768,    81,   104,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,  3063,    18,   361,-32768,
-32768,-32768,   362,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,  2538,-32768,-32768,-32768,   354,
-32768,-32768,-32768,   368,-32768,-32768,   376,-32768,   376,-32768,
-32768,  3168,-32768,   376,  3168,   477,   361,  3168,   334,   478,
   383,   481,    47,   490,    47,-32768,   515,  3168,   381,   486,
   394,-32768,  3273,-32768,   524,    47,   526,-32768,-32768,  3168,
   361,  2326,   716,   452,   454,  3168,  2432,   455,   456,   445,
   408,   243,   267,   122,   129,   150,   361,   368,   173,-32768,
   396,-32768,-32768,-32768,-32768,   191,-32768,   508,  3168,  3168,
   361,   399,   399,  1526,-32768,-32768,     1,-32768,   361,    52,
   509,    13,   510,   411,-32768,   376,-32768,-32768,   334,   534,
   244,   513,   414,   517,-32768,-32768,   361,-32768,-32768,-32768,
-32768,   546,   547,  1901,   361,   422,   419,-32768,   423,   428,
   434,-32768,-32768,-32768,   423,   176,-32768,   361,-32768,   493,
-32768,   435,   269,     3,   441,   438,-32768,    76,   439,-32768,
-32768,-32768,-32768,-32768,-32768,   239,    15,-32768,   525,   541,
-32768,   361,  3168,-32768,-32768,-32768,-32768,-32768,   350,   988,
  1258,   442,-32768,   563,   361,   448,   449,   450,   447,   453,
   458,   444,-32768,   457,   -35,   -39,-32768,   525,-32768,-32768,
   460,   446,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   196,   207,   462,-32768,-32768,-32768,-32768,   229,-32768,-32768,
   461,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   376,-32768,
  3168,  3168,   361,-32768,   459,   468,  3168,  3168,  3168,  1807,
-32768,  3063,   288,   463,   464,-32768,   466,-32768,  1807,   361,
   361,-32768,-32768,-32768,-32768,-32768,   465,-32768,   465,   852,
   361,   368,   282,-32768,-32768,-32768,  1807,   469,-32768,-32768,
   472,   472,  3168,   418,-32768,-32768,   470,   471,-32768,   244,
  1258,-32768,   414,   118,-32768,   476,   285,-32768,   361,-32768,
  2748,    32,-32768,    30,-32768,   526,  3168,   473,-32768,  2853,
-32768,-32768,-32768,  2643,  1807,   369,   475,-32768,-32768,   301,
-32768,-32768,-32768,   303,    75,  1392,-32768,   482,-32768,   361,
   361,   483,   544,    23,-32768,   480,   263,   304,-32768,   484,
   479,-32768,   399,  1631,   485,   487,-32768,-32768,  1392,-32768,
-32768,  1392,-32768,   489,-32768,-32768,   361,   361,-32768,   361,
   361,   -38,    79,   491,-32768,-32768,   584,-32768,-32768,   399,
   495,-32768,  1526,-32768,   580,   494,  1122,-32768,-32768,   361,
    40,  2008,  2008,    47,    47,   320,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,   360,   399,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   210,-32768,   547,   492,-32768,   488,   500,
   499,-32768,-32768,   361,   444,   501,  1807,   503,-32768,-32768,
-32768,   606,-32768,   212,-32768,   625,   511,-32768,   514,    75,
-32768,  1526,-32768,    37,-32768,-32768,  1807,-32768,   516,-32768,
   638,-32768,   506,     4,   148,   147,-32768,-32768,-32768,-32768,
   512,   -39,-32768,  1718,   380,   519,   521,-32768,-32768,-32768,
-32768,   576,   603,   548,  3168,-32768,-32768,   -40,    -6,    24,
     8,    84,    89,   549,   418,   465,   522,   523,-32768,  3273,
-32768,-32768,   518,-32768,  2853,-32768,  2853,   321,-32768,-32768,
   217,-32768,-32768,   152,   527,-32768,   528,   -70,   529,-32768,
    17,   530,   531,   532,   520,-32768,  1258,  1807,   535,-32768,
  1798,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   538,  1807,
   640,   551,   629,-32768,   594,-32768,   361,-32768,   107,  1807,
-32768,-32768,   472,-32768,-32768,-32768,   244,-32768,-32768,   414,
-32768,-32768,   579,-32768,-32768,-32768,-32768,   537,   542,   501,
-32768,   657,-32768,-32768,-32768,   543,-32768,  1526,  1526,-32768,
-32768,-32768,    25,-32768,   545,-32768,   676,    38,   328,-32768,
-32768,-32768,  1258,-32768,   395,-32768,   339,-32768,   662,   650,
    93,   652,-32768,-32768,-32768,-32768,-32768,   554,  3273,   524,
   552,-32768,-32768,-32768,-32768,   553,-32768,-32768,   684,   556,
-32768,   520,-32768,-32768,-32768,-32768,-32768,   521,-32768,  1807,
-32768,  1807,   660,-32768,-32768,-32768,-32768,-32768,   561,   562,
   233,-32768,   555,    93,-32768,-32768,    93,  3446,-32768,   560,
   680,   676,   556,   696,-32768,   551,-32768,-32768,-32768,   605,
  2958,  3168,   670,    34,-32768,-32768,-32768,    93,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,  3630,  3538,-32768,-32768,-32768,-32768,
-32768,   524,   570,   571,-32768,   578,   697,  1901,  3168,   309,
    19,  3168,-32768,-32768,-32768,  3368,-32768,-32768,-32768,-32768,
   575,   581,   573,   317,   335,-32768,  1807,   361,-32768,   236,
   585,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   345,-32768,
  1807,   679,-32768,   236,   583,  1807,-32768,-32768,-32768,   711,
   712,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,   710,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   673,-32768,-32768,-32768,-32768,-32768,    39,-32768,
-32768,   667,-32768,-32768,-32768,   -48,  -140,-32768,  -135,-32768,
-32768,-32768,   195,-32768,-32768,-32768,-32768,-32768,-32768,   126,
  -168,  -181,-32768,-32768,-32768,    12,  -415,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   533,  -419,  -409,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  -116,
-32768,  -179,  -162,   -31,-32768,  -102,-32768,   192,-32768,   536,
  -285,-32768,   259,   274,   424,-32768,-32768,   302,-32768,-32768,
-32768,-32768,-32768,   116,-32768,-32768,   377,-32768,-32768,  -642,
-32768,    66,-32768,-32768,-32768,    78,-32768,-32768,-32768,-32768,
    31,    43,-32768,-32768,-32768,   539,   -46,-32768,-32768,-32768,
-32768,   162,-32768,-32768,-32768,-32768,   109,-32768,-32768,   175,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,   -28,  -730,-32768,
-32768,-32768,  -147,-32768,-32768,   -23,-32768,    16,  -201,  -456,
  -231,  -236,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,   451,-32768,   404,  -522,-32768,-32768,  -136,-32768,
  -212,-32768,-32768,  -206,-32768,  -196,  -406,   363,-32768,   218,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   240,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   224,-32768,-32768,-32768,  -378,-32768,-32768,-32768,-32768,-32768,
-32768,  -677,    44,-32768,-32768,-32768,-32768,    36,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,    54,    42,-32768,-32768,   -50,
-32768,-32768,-32768,-32768,-32768,  -100,-32768,-32768,  -174,  -367
};


#define	YYLAST		3768


static const short yytable[] = {   119,
   167,   258,   194,   198,   172,   174,   412,   522,   532,   409,
   536,   394,   267,   309,   456,   460,   212,   395,   442,   378,
   225,   389,   498,   499,   539,   557,   470,   228,   365,   619,
   310,   397,   259,   578,   374,   169,   762,   650,   375,   621,
   718,   763,   680,   402,   717,   331,   431,   213,   280,   827,
   680,   653,   306,   171,   530,    79,   648,   307,    13,   398,
   467,   408,   171,    34,    79,   818,   223,   653,   207,   770,
   208,  -383,   651,    82,     1,   575,   308,    14,   310,   547,
    71,   432,    82,   585,   399,   818,   654,    15,   269,   439,
   815,   548,   193,   331,   193,   681,   569,   221,   682,   405,
   733,   214,   654,   681,   471,    95,   682,   468,   -16,   804,
   734,     2,    25,   227,    95,   215,   229,     4,   586,   232,
   309,   309,   236,   519,   375,   456,   242,   657,   244,   247,
   490,     5,   660,   193,   255,   117,  -169,   310,   310,   264,
   490,   268,   288,   255,   490,   193,   443,   363,   255,   193,
   650,   193,   331,   331,   455,   619,   193,     9,   190,   306,
   306,   311,   658,   484,   307,   307,   531,   661,   191,   332,
   380,   381,   489,   622,   719,   391,   518,   392,   517,   304,
   813,   196,    10,   308,   308,   651,   117,   670,    11,   449,
   494,   191,   236,   374,   225,   539,    17,   375,   735,   736,
   737,   738,   739,   740,   675,   419,  -459,   376,   333,  -459,
   309,   192,   374,   193,   374,   178,   375,   435,   375,    18,
   435,   673,   476,   375,    19,   529,   597,   310,   540,   438,
   408,   309,   741,   674,   197,   762,   193,    20,   837,   528,
   763,   374,   331,   838,   450,   375,   556,   310,   310,   306,
   407,   533,   527,  -525,   307,   437,   438,  -525,    80,    81,
  -526,   564,   331,   331,  -526,   538,   309,   568,   311,   311,
   306,   212,   486,   308,   705,   307,   457,   332,  -459,   193,
   580,  -527,    21,   310,   193,  -527,   395,   178,   628,   309,
    28,   801,   309,  -382,   308,    29,    30,    22,   331,    39,
   589,   591,    31,    32,   371,   306,   310,   425,   372,   310,
   307,   426,   477,   478,   596,   333,   333,   309,   480,   481,
   482,   331,    23,   207,   331,   208,   224,   598,   306,   308,
   606,   306,  -170,   307,   310,    41,   307,   224,   801,   801,
   171,   691,    79,  -172,    38,   395,    42,   439,   553,   331,
   556,    43,   308,    72,   500,   308,   306,    48,   311,   801,
    82,   307,    49,    50,    73,  -220,   332,   634,  -220,    51,
    52,   541,   255,   234,   250,   251,   248,   249,   534,   311,
   308,   255,   178,   250,   251,   255,   532,   332,   248,   249,
   451,   452,    95,   224,   559,   250,   251,  -386,  -523,  -172,
   429,    75,  -523,  -386,   430,   333,   179,   723,   382,   383,
   384,   385,   386,   492,   311,   566,   525,   493,   258,   180,
   526,   692,   332,   707,   634,   706,   333,   501,   502,   503,
   504,   505,   543,   696,   545,   560,   544,   311,   546,   561,
   311,   193,   826,   704,   391,   332,   392,   309,   332,   193,
   834,   594,   671,   588,   590,   595,   672,   592,   593,   721,
   181,   333,   182,   722,   310,   311,   714,   193,   835,   184,
   729,   395,   395,   332,   730,   186,   843,   408,   183,   331,
   844,   195,   199,   185,   333,   188,   306,   333,   187,   189,
   222,   307,  -385,   193,   310,   635,   636,   637,   638,   168,
   170,   173,   175,   614,   223,   618,   224,   230,   239,   331,
   308,   241,   333,   309,   724,   725,   726,   727,   683,   240,
   243,   245,   252,   757,   253,   758,   259,   528,   265,   361,
   310,   362,   367,   368,   369,   370,   647,   373,   379,   401,
   403,   404,   249,   410,   411,   331,   483,   413,   415,   416,
   375,   255,   306,   420,   421,   422,   255,   307,   255,   423,
   280,   281,   282,   283,   284,   285,   286,   287,   288,   424,
   427,   428,   433,   434,   446,   436,   308,   448,   461,   462,
   -57,   -78,   -79,   463,   464,   475,   541,   581,   582,  -171,
   -55,  -458,   466,  -459,   430,   311,   474,   291,  -173,   479,
   487,   490,   497,   332,   488,   495,   515,   516,   524,   535,
   542,   558,   552,   554,   295,   563,   296,   562,   570,   576,
   836,   601,   608,   571,   297,   574,   579,   600,   610,   614,
   391,   618,   392,   602,   845,   603,   605,   298,   607,   849,
   557,   627,   333,   611,   641,   612,   625,   643,   629,   640,
   644,   645,   695,   663,   669,   666,   667,   698,   677,   701,
   255,   311,   686,   678,   688,   702,   685,   687,   708,   332,
   679,   693,   709,   711,   454,   699,   712,   710,   621,   731,
   732,   716,   747,   178,   748,   435,   718,   751,   752,   303,
   759,   304,   754,   760,   761,   802,   803,   768,   805,   807,
   812,   819,   820,   821,   823,   830,   833,   831,   333,   846,
   851,   852,   810,   811,   848,   841,    12,    74,   278,   176,
   599,   750,   279,    78,    79,   668,   604,   572,   313,   366,
    80,    81,   280,   281,   282,   283,   284,   285,   286,   287,
   288,   473,    82,   289,    83,   573,   694,   551,   715,    84,
    85,    86,   755,    87,    88,   713,   665,   703,   290,   824,
   825,   753,    89,   828,    90,   656,   816,   613,    91,   291,
   292,    92,    93,    94,    95,   485,   523,   406,   293,    96,
    97,   756,    98,   609,   626,   294,   295,   769,   296,    99,
   100,   101,   102,   847,     0,     0,   297,   806,   103,   814,
   104,   105,   106,   191,     0,     0,   107,     0,   108,   298,
     0,     0,     0,     0,   109,   110,   111,   112,   113,     0,
   299,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   116,   300,     0,   301,     0,
     0,     0,   302,   118,   453,     0,     0,     0,   279,    78,
    79,   303,     0,   304,     0,     0,    80,    81,   280,   281,
   282,   283,   284,   285,   286,   287,   288,     0,    82,   289,
    83,     0,     0,     0,     0,    84,    85,    86,     0,    87,
    88,     0,     0,     0,     0,     0,     0,     0,    89,     0,
    90,     0,     0,     0,    91,   291,   292,    92,    93,    94,
    95,     0,     0,     0,   293,    96,    97,     0,    98,     0,
     0,   294,   295,     0,   296,    99,   100,   101,   102,     0,
     0,     0,   297,     0,   103,     0,   104,   105,   106,   191,
     0,     0,   107,     0,   108,   298,     0,     0,     0,     0,
   109,   110,   111,   112,   113,     0,   299,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   116,   454,   455,   301,     0,     0,     0,   302,   118,
   453,     0,     0,     0,   279,    78,    79,   303,     0,   304,
     0,     0,    80,    81,   280,   281,   282,   283,   284,   285,
   286,   287,   288,     0,    82,   289,    83,     0,     0,     0,
     0,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,   291,   292,    92,    93,    94,    95,     0,     0,     0,
   293,    96,    97,     0,    98,     0,     0,   294,   295,     0,
   296,    99,   100,   101,   102,     0,     0,     0,   297,     0,
   103,     0,   104,   105,   106,   191,     0,     0,   107,     0,
   108,   298,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,   299,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   116,   454,   455,
   301,     0,     0,     0,   278,   118,     0,     0,   279,    78,
    79,     0,     0,   303,     0,   304,    80,    81,   280,   281,
   282,   283,   284,   285,   286,   287,   288,     0,    82,   289,
    83,     0,     0,     0,     0,    84,    85,    86,     0,    87,
    88,     0,     0,     0,     0,     0,     0,     0,    89,     0,
    90,     0,     0,     0,    91,   291,   292,    92,    93,    94,
    95,     0,     0,     0,   293,    96,    97,     0,    98,     0,
     0,   294,   295,     0,   296,    99,   100,   101,   102,     0,
     0,     0,   297,     0,   103,     0,   104,   105,   106,   191,
     0,     0,   107,     0,   108,   298,     0,     0,     0,     0,
   109,   110,   111,   112,   113,     0,   299,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   116,   454,     0,   301,     0,     0,     0,   302,   118,
   278,     0,     0,     0,   279,    78,    79,   303,     0,   304,
     0,     0,    80,    81,   280,   281,   282,   283,   284,   285,
   286,   287,   288,     0,    82,   289,    83,     0,     0,     0,
     0,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,   291,   292,    92,    93,    94,    95,     0,     0,     0,
   293,    96,    97,     0,    98,     0,     0,   294,   295,     0,
   296,    99,   100,   101,   102,     0,     0,     0,   297,     0,
   103,     0,   104,   105,   106,   191,     0,     0,   107,     0,
   108,   298,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,   299,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,   116,   454,     0,
   301,     0,     0,     0,   278,   118,     0,     0,   279,    78,
    79,     0,     0,   303,     0,   304,    80,    81,   280,   281,
   282,   283,   284,   285,   286,   287,   288,     0,    82,     0,
    83,     0,     0,     0,     0,    84,    85,    86,     0,    87,
    88,     0,     0,     0,     0,     0,     0,     0,    89,     0,
    90,     0,     0,     0,    91,   291,   292,    92,    93,    94,
    95,     0,     0,     0,   293,    96,    97,     0,    98,     0,
     0,   294,   295,     0,   296,    99,   100,   101,   102,     0,
     0,     0,   297,     0,   103,     0,   104,   105,   106,   191,
     0,     0,   107,     0,   108,   298,     0,     0,     0,     0,
   109,   110,   111,   112,   113,     0,   299,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   116,   454,     0,   301,     0,     0,     0,   278,   118,
     0,     0,   279,    78,    79,     0,     0,   303,     0,   304,
    80,    81,   280,   281,   282,   283,   284,   285,   286,   287,
   288,     0,    82,     0,    83,     0,     0,     0,     0,    84,
    85,    86,     0,    87,    88,     0,     0,     0,     0,     0,
     0,     0,    89,     0,    90,     0,     0,     0,    91,   291,
     0,    92,    93,    94,    95,     0,     0,     0,     0,    96,
    97,     0,    98,     0,     0,     0,   295,     0,   296,    99,
   100,   101,   102,     0,     0,     0,   297,     0,   103,     0,
   104,   105,   106,     0,     0,     0,   107,     0,   108,   298,
     0,     0,     0,     0,   109,   110,   111,   112,   113,     0,
     0,     0,     0,   565,     0,     0,     0,   279,    78,    79,
     0,     0,     0,     0,     0,    80,    81,   280,     0,     0,
     0,     0,     0,     0,     0,   116,   390,    82,     0,    83,
     0,     0,     0,   118,    84,    85,    86,     0,    87,    88,
     0,   303,     0,   304,     0,     0,     0,    89,     0,    90,
     0,     0,     0,    91,     0,     0,    92,    93,    94,    95,
     0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
     0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
     0,     0,     0,   103,     0,   104,   105,   106,     0,     0,
   483,   107,     0,   108,   375,     0,     0,     0,     0,   109,
   110,   111,   112,   113,   280,   281,   282,   283,   284,   285,
   286,   287,   288,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
   116,     0,     0,     0,     0,     0,     0,     0,   118,     0,
     0,   291,     0,     0,     0,     0,     0,     0,   304,     0,
     0,     0,     0,     0,     0,     0,   630,     0,   295,     0,
   296,     0,     0,     0,     0,     0,     0,     0,   297,     0,
   483,     0,     0,     0,   375,     0,     0,     0,     0,   483,
     0,   298,     0,   375,   280,   281,   282,   283,   284,   285,
   286,   287,   288,   280,   281,   282,   283,   284,   285,   286,
   287,   288,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   454,     0,
     0,   291,     0,     0,     0,     0,     0,   631,     0,     0,
   291,     0,     0,   303,     0,   304,   630,     0,   295,     0,
   296,     0,     0,     0,     0,     0,     0,   295,   297,   296,
     0,     0,     0,     0,     0,     0,     0,   297,     0,     0,
     0,   298,     0,     0,     0,     0,     0,     0,     0,     0,
   298,     0,     0,    76,     0,     0,     0,    77,    78,    79,
     0,     0,     0,     0,     0,    80,    81,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    82,   454,    83,
     0,     0,     0,     0,    84,    85,    86,   454,    87,    88,
     0,     0,     0,   303,     0,   304,     0,    89,     0,    90,
     0,     0,   303,    91,   304,     0,    92,    93,    94,    95,
     0,     0,     0,     0,    96,    97,     0,    98,     0,     0,
     0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
     0,     0,     0,   103,     0,   104,   105,   106,     0,     0,
     0,   107,     0,   108,     0,     0,     0,     0,     0,   109,
   110,   111,   112,   113,     0,     0,     0,     0,     0,     0,
    76,     0,     0,     0,    77,    78,    79,   382,   383,   384,
   385,   386,    80,    81,     0,     0,     0,     0,     0,     0,
   116,     0,     0,     0,    82,     0,    83,     0,   118,     0,
   178,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,     0,     0,    92,    93,    94,    95,     0,     0,     0,
     0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
   103,     0,   104,   105,   106,     0,     0,     0,   107,     0,
   108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,     0,     0,     0,    76,     0,     0,     0,    77,
    78,    79,     0,     0,     0,     0,     0,    80,    81,     0,
     0,     0,     0,     0,     0,     0,     0,   116,     0,    82,
     0,    83,     0,     0,     0,   118,    84,    85,    86,     0,
    87,    88,     0,     0,     0,     0,     0,     0,     0,    89,
     0,    90,     0,     0,     0,    91,     0,     0,    92,    93,
    94,    95,     0,     0,     0,     0,    96,    97,     0,    98,
     0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     0,     0,     0,   107,     0,   108,     0,     0,     0,     0,
     0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
     0,     0,     0,    76,   114,   115,     0,    77,    78,    79,
     0,     0,     0,     0,     0,    80,    81,     0,     0,     0,
     0,     0,   116,   117,     0,     0,     0,    82,     0,    83,
   118,   165,     0,     0,    84,    85,    86,     0,    87,    88,
     0,     0,     0,     0,     0,     0,     0,    89,     0,    90,
     0,     0,     0,    91,     0,     0,    92,    93,    94,    95,
     0,     0,     0,     0,    96,    97,     0,    98,   166,     0,
     0,     0,     0,     0,    99,   100,   101,   102,     0,     0,
     0,     0,     0,   103,     0,   104,   105,   106,     0,     0,
     0,   107,     0,   108,     0,     0,     0,     0,     0,   109,
   110,   111,   112,   113,     0,     0,     0,     0,   254,     0,
     0,     0,    77,    78,    79,     0,     0,     0,     0,     0,
    80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
   116,   117,    82,     0,    83,     0,     0,     0,   118,    84,
    85,    86,     0,    87,    88,     0,     0,   270,     0,     0,
     0,     0,    89,     0,    90,     0,     0,     0,    91,     0,
     0,    92,    93,    94,    95,     0,     0,     0,     0,    96,
    97,     0,    98,     0,     0,     0,     0,     0,     0,    99,
   100,   101,   102,     0,     0,     0,     0,     0,   103,     0,
   104,   105,   106,     0,     0,     0,   107,     0,   108,     0,
     0,     0,     0,     0,   109,   110,   111,   112,   113,     0,
     0,     0,     0,     0,   254,     0,     0,     0,    77,    78,
    79,     0,     0,     0,     0,     0,    80,    81,     0,     0,
     0,     0,     0,     0,     0,   116,     0,   271,    82,     0,
    83,     0,   272,   118,     0,    84,    85,    86,     0,    87,
    88,     0,     0,   270,     0,     0,     0,     0,    89,     0,
    90,     0,     0,     0,    91,     0,     0,    92,    93,    94,
    95,     0,     0,     0,     0,    96,    97,     0,    98,     0,
     0,     0,     0,     0,     0,    99,   100,   101,   102,     0,
     0,     0,     0,     0,   103,     0,   104,   105,   106,     0,
     0,     0,   107,     0,   108,     0,     0,     0,     0,     0,
   109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
    76,     0,     0,     0,    77,    78,    79,     0,     0,     0,
     0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
     0,   116,     0,   364,    82,     0,    83,     0,   272,   118,
     0,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,   219,     0,
    91,     0,     0,    92,    93,    94,    95,     0,   220,     0,
     0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
   103,     0,   104,   105,   106,     0,     0,     0,   107,     0,
   108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,     0,     0,     0,   254,     0,     0,     0,    77,
    78,    79,     0,     0,     0,     0,     0,    80,    81,     0,
     0,     0,     0,     0,     0,     0,     0,   116,     0,    82,
     0,    83,     0,     0,     0,   118,    84,    85,    86,     0,
    87,    88,     0,     0,   270,     0,     0,     0,     0,    89,
     0,    90,     0,     0,     0,    91,     0,     0,    92,    93,
    94,    95,     0,     0,     0,     0,    96,    97,     0,    98,
     0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     0,     0,     0,   107,     0,   108,     0,     0,     0,     0,
     0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
   254,     0,     0,     0,    77,    78,    79,     0,     0,     0,
     0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
     0,     0,   116,     0,    82,     0,    83,     0,     0,   272,
   118,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,     0,     0,    92,    93,    94,    95,     0,     0,     0,
     0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
   103,     0,   104,   105,   106,     0,     0,     0,   107,     0,
   108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,     0,     0,     0,   254,     0,     0,     0,    77,
    78,    79,     0,     0,     0,     0,     0,    80,    81,     0,
     0,     0,     0,     0,     0,     0,     0,   116,     0,    82,
     0,    83,     0,     0,   272,   118,    84,    85,    86,     0,
    87,    88,     0,     0,   270,     0,     0,     0,     0,    89,
     0,    90,     0,     0,     0,    91,     0,     0,    92,    93,
    94,    95,     0,     0,     0,     0,    96,    97,     0,    98,
     0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     0,     0,     0,   107,     0,   108,     0,     0,     0,     0,
     0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
   808,     0,     0,     0,    77,    78,    79,     0,     0,     0,
     0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
     0,     0,   116,     0,    82,     0,    83,     0,     0,     0,
   118,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,     0,     0,    92,    93,    94,    95,     0,     0,     0,
     0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
   103,     0,   104,   105,   106,     0,     0,     0,   107,     0,
   108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
   113,   809,     0,     0,     0,   202,     0,     0,     0,    77,
   203,   204,     0,     0,     0,     0,     0,   205,   206,     0,
     0,     0,     0,     0,     0,     0,     0,   116,     0,    82,
     0,    83,     0,     0,     0,   118,    84,    85,    86,     0,
    87,    88,     0,     0,     0,     0,     0,     0,     0,    89,
     0,    90,     0,     0,     0,    91,     0,     0,    92,    93,
    94,    95,     0,     0,     0,     0,    96,    97,     0,    98,
     0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     0,     0,     0,   107,     0,   108,     0,     0,     0,     0,
     0,   109,   110,   111,   112,   113,     0,     0,     0,     0,
    76,     0,     0,     0,    77,    78,    79,     0,     0,     0,
     0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
     0,     0,   116,     0,    82,     0,    83,     0,     0,     0,
   118,    84,    85,    86,     0,    87,    88,     0,     0,     0,
     0,     0,     0,     0,    89,     0,    90,     0,     0,     0,
    91,     0,     0,    92,    93,    94,    95,     0,     0,     0,
     0,    96,    97,     0,    98,     0,     0,     0,     0,     0,
     0,    99,   100,   101,   102,     0,     0,     0,     0,     0,
   103,     0,   104,   105,   106,     0,     0,     0,   107,     0,
   108,     0,     0,     0,     0,     0,   109,   110,   111,   112,
   113,     0,     0,     0,     0,   254,     0,     0,     0,    77,
    78,    79,     0,     0,     0,     0,     0,    80,    81,     0,
     0,     0,     0,     0,     0,     0,     0,   116,     0,    82,
     0,    83,     0,     0,     0,   118,    84,    85,    86,     0,
    87,    88,     0,     0,     0,     0,     0,     0,     0,    89,
     0,    90,     0,     0,     0,    91,     0,     0,    92,    93,
    94,    95,     0,     0,     0,     0,    96,    97,     0,    98,
     0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     0,     0,     0,     0,     0,   103,     0,   104,   105,   106,
     0,     0,     0,   107,     0,   108,     0,     0,     0,     0,
     0,   109,   110,   111,   112,   113,     0,   382,   383,   384,
   385,   386,     0,     0,   771,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   772,   116,   773,     0,   774,   775,     0,     0,     0,
   118,     0,     0,     0,   776,   777,   778,     0,     0,     0,
   779,   780,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   781,     0,   782,     0,     0,     0,     0,   783,     0,
     0,   784,     0,   785,   786,     0,     0,     0,   787,     0,
     0,     0,   788,   789,   790,   382,   383,   384,   385,   386,
     0,   791,   771,   792,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   772,
     0,   773,     0,   774,   775,     0,     0,     0,     0,     0,
     0,     0,   776,   777,   778,     0,     0,     0,   779,   780,
     0,     0,     0,   794,     0,   795,   829,     0,     0,   781,
     0,   782,     0,     0,     0,     0,   783,     0,     0,   784,
     0,   785,   786,     0,     0,     0,   787,     0,     0,     0,
   788,   789,   790,     0,     0,     0,     0,     0,     0,   791,
     0,   792,     0,     0,     0,     0,     0,   382,   383,   384,
   385,   386,     0,     0,   771,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   772,     0,   773,     0,   774,   775,   793,     0,     0,
     0,   794,     0,   795,   776,   777,   778,     0,     0,     0,
   779,   780,     0,     0,     0,     0,     0,     0,     0,     0,
     0,   781,     0,   782,     0,     0,     0,     0,   783,     0,
     0,   784,     0,   785,   786,     0,     0,     0,   787,     0,
     0,     0,   788,   789,   790,     0,     0,     0,     0,     0,
     0,   791,     0,   792,     0,     0,     0,     0,     0,   382,
   383,   384,   385,   386,     0,     0,   771,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   772,     0,   773,     0,   774,   775,   817,
     0,     0,     0,   794,     0,   795,   776,   777,   778,     0,
     0,     0,   779,   780,     0,     0,     0,     0,     0,     0,
     0,     0,     0,   781,     0,   782,     0,     0,     0,     0,
   783,     0,     0,   784,     0,   785,   786,     0,     0,     0,
   787,     0,     0,     0,   788,   789,   790,     0,     0,     0,
     0,     0,     0,   791,     0,   792,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   794,     0,   795
};

static const short yycheck[] = {    48,
    49,   183,   105,   106,    51,    52,   243,   414,   424,   241,
   430,   224,   187,   193,   300,   301,   117,   224,     4,   216,
   157,   223,   401,   402,   434,     3,    66,   164,   197,   552,
   193,    31,     3,   490,     3,    31,     3,    44,     7,     3,
     3,     8,    26,    31,   687,   193,    44,    30,    17,    31,
    26,    44,   193,     7,   422,     9,    97,   193,    32,     8,
    96,   241,     7,    25,     9,   796,   137,    44,   117,   747,
   117,   142,    79,    27,     7,   114,   193,    51,   241,     5,
    42,    79,    27,    44,    33,   816,    79,    61,   191,   286,
   768,    17,   133,   241,   133,    79,   464,   146,    82,   236,
     8,    84,    79,    79,   144,    59,    82,   143,    48,   752,
    18,   131,    52,   162,    59,    98,   165,     3,    79,   168,
   300,   301,   169,     6,     7,   411,   173,    44,   175,   178,
   137,    17,    44,   133,   183,   131,   133,   300,   301,   186,
   137,   190,    25,   192,   137,   133,   132,   196,   197,   133,
    44,   133,   300,   301,   132,   678,   133,    46,    78,   300,
   301,   193,    79,   370,   300,   301,   137,    79,    88,   193,
   219,   220,   379,   137,   137,   224,   413,   224,   410,   148,
   147,    78,   133,   300,   301,    79,   131,   607,   132,   292,
   397,    88,   239,     3,   331,   605,    17,     7,   106,   107,
   108,   109,   110,   111,   611,   254,   131,    17,   193,   131,
   390,   131,     3,   133,     3,   140,     7,   142,     7,    92,
   142,     5,   359,     7,    92,   422,    17,   390,   435,    18,
   410,   411,   140,    17,   131,     3,   133,    92,     3,   421,
     8,     3,   390,     8,   293,     7,   453,   410,   411,   390,
     7,   426,   421,   132,   390,    17,    18,   136,    15,    16,
   132,   463,   410,   411,   136,   434,   446,   464,   300,   301,
   411,   372,   373,   390,   653,   411,   300,   301,   131,   133,
   493,   132,    31,   446,   133,   136,   493,   140,   142,   469,
     3,   748,   472,   142,   411,     8,     9,   134,   446,    62,
   502,   503,    15,    16,   132,   446,   469,   132,   136,   472,
   446,   136,   361,   362,   516,   300,   301,   497,   367,   368,
   369,   469,    33,   372,   472,   372,   131,   524,   469,   446,
   537,   472,   137,   469,   497,   135,   472,   131,   795,   796,
     7,   627,     9,   137,    48,   552,   136,   544,   451,   497,
   557,   131,   469,   132,   403,   472,   497,     3,   390,   816,
    27,   497,     8,     9,   135,   137,   390,   574,   140,    15,
    16,     3,   421,    40,    15,    16,     8,     9,   427,   411,
   497,   430,   140,    15,    16,   434,   802,   411,     8,     9,
    41,    42,    59,   131,   132,    15,    16,   131,   132,   137,
   132,    55,   136,   131,   136,   390,   137,   693,    10,    11,
    12,    13,    14,   132,   446,   464,   132,   136,   600,    45,
   136,   628,   446,   660,   631,   657,   411,    10,    11,    12,
    13,    14,   132,   640,   132,   132,   136,   469,   136,   136,
   472,   133,   134,   650,   493,   469,   493,   627,   472,   133,
   134,   132,   132,   502,   503,   136,   136,   504,   505,   132,
    89,   446,    89,   136,   627,   497,   679,   133,   134,    80,
   132,   678,   679,   497,   136,    78,   132,   657,   131,   627,
   136,   105,   106,   131,   469,    60,   627,   472,   131,    89,
   137,   627,   131,   133,   657,   116,   117,   118,   119,    49,
    50,    51,    52,   552,   137,   552,   131,    31,    31,   657,
   627,    31,   497,   693,   120,   121,   122,   123,   621,   137,
    31,     7,    37,   730,   131,   732,     3,   709,     3,    78,
   693,    78,    78,    78,    90,   128,   585,   142,    31,    31,
    31,   131,     9,    31,   131,   693,     3,    31,     3,     3,
     7,   600,   693,   132,   136,   133,   605,   693,   607,   132,
    17,    18,    19,    20,    21,    22,    23,    24,    25,   136,
    78,   137,   132,   136,    50,   137,   693,    37,   137,    17,
   133,   133,   133,   137,   141,   140,     3,     8,    95,   137,
   133,   131,   136,   131,   136,   627,   137,    54,   137,   132,
   137,   137,   131,   627,   139,   137,   137,   137,   133,   137,
   136,   132,   131,   131,    71,   137,    73,   134,   134,   129,
   827,   134,    17,   137,    81,   137,   132,   136,     4,   678,
   679,   678,   679,   134,   841,   137,   136,    94,   136,   846,
     3,   136,   627,   133,   124,   132,   131,    72,   137,   131,
    48,   104,   115,   105,   137,   134,   134,    18,   132,    31,
   709,   693,   132,   136,   145,    72,   137,   136,    90,   693,
   142,   137,   136,    17,   131,   125,   134,   136,     3,    18,
    31,   137,    31,   140,   131,   142,     3,   136,   136,   146,
    31,   148,   137,   133,   133,   136,    17,   143,     3,    95,
    31,   132,   132,   126,     8,   131,   134,   127,   693,    31,
     0,     0,   761,   762,   132,   131,     7,    45,     3,    53,
   526,   710,     7,     8,     9,   600,   535,   469,   193,   197,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,   318,    27,    28,    29,   472,   631,   446,   683,    34,
    35,    36,   722,    38,    39,   678,   595,   649,    43,   808,
   809,   719,    47,   812,    49,   591,   795,   550,    53,    54,
    55,    56,    57,    58,    59,   372,   414,   239,    63,    64,
    65,   728,    67,   544,   561,    70,    71,   744,    73,    74,
    75,    76,    77,   844,    -1,    -1,    81,   756,    83,   764,
    85,    86,    87,    88,    -1,    -1,    91,    -1,    93,    94,
    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,   133,    -1,
    -1,    -1,   137,   138,     3,    -1,    -1,    -1,     7,     8,
     9,   146,    -1,   148,    -1,    -1,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
    29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
    59,    -1,    -1,    -1,    63,    64,    65,    -1,    67,    -1,
    -1,    70,    71,    -1,    73,    74,    75,    76,    77,    -1,
    -1,    -1,    81,    -1,    83,    -1,    85,    86,    87,    88,
    -1,    -1,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
    99,   100,   101,   102,   103,    -1,   105,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   130,   131,   132,   133,    -1,    -1,    -1,   137,   138,
     3,    -1,    -1,    -1,     7,     8,     9,   146,    -1,   148,
    -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
    -1,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
    63,    64,    65,    -1,    67,    -1,    -1,    70,    71,    -1,
    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
    83,    -1,    85,    86,    87,    88,    -1,    -1,    91,    -1,
    93,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
   133,    -1,    -1,    -1,     3,   138,    -1,    -1,     7,     8,
     9,    -1,    -1,   146,    -1,   148,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
    29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
    59,    -1,    -1,    -1,    63,    64,    65,    -1,    67,    -1,
    -1,    70,    71,    -1,    73,    74,    75,    76,    77,    -1,
    -1,    -1,    81,    -1,    83,    -1,    85,    86,    87,    88,
    -1,    -1,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
    99,   100,   101,   102,   103,    -1,   105,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     3,    -1,    -1,    -1,     7,     8,     9,   146,    -1,   148,
    -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    -1,    27,    28,    29,    -1,    -1,    -1,
    -1,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    54,    55,    56,    57,    58,    59,    -1,    -1,    -1,
    63,    64,    65,    -1,    67,    -1,    -1,    70,    71,    -1,
    73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    -1,
    83,    -1,    85,    86,    87,    88,    -1,    -1,    91,    -1,
    93,    94,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,    -1,
   133,    -1,    -1,    -1,     3,   138,    -1,    -1,     7,     8,
     9,    -1,    -1,   146,    -1,   148,    15,    16,    17,    18,
    19,    20,    21,    22,    23,    24,    25,    -1,    27,    -1,
    29,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,    38,
    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
    49,    -1,    -1,    -1,    53,    54,    55,    56,    57,    58,
    59,    -1,    -1,    -1,    63,    64,    65,    -1,    67,    -1,
    -1,    70,    71,    -1,    73,    74,    75,    76,    77,    -1,
    -1,    -1,    81,    -1,    83,    -1,    85,    86,    87,    88,
    -1,    -1,    91,    -1,    93,    94,    -1,    -1,    -1,    -1,
    99,   100,   101,   102,   103,    -1,   105,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   130,   131,    -1,   133,    -1,    -1,    -1,     3,   138,
    -1,    -1,     7,     8,     9,    -1,    -1,   146,    -1,   148,
    15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
    25,    -1,    27,    -1,    29,    -1,    -1,    -1,    -1,    34,
    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    53,    54,
    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
    65,    -1,    67,    -1,    -1,    -1,    71,    -1,    73,    74,
    75,    76,    77,    -1,    -1,    -1,    81,    -1,    83,    -1,
    85,    86,    87,    -1,    -1,    -1,    91,    -1,    93,    94,
    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   130,   131,    27,    -1,    29,
    -1,    -1,    -1,   138,    34,    35,    36,    -1,    38,    39,
    -1,   146,    -1,   148,    -1,    -1,    -1,    47,    -1,    49,
    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    -1,    -1,
    -1,    -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
    -1,    -1,    -1,    83,    -1,    85,    86,    87,    -1,    -1,
     3,    91,    -1,    93,     7,    -1,    -1,    -1,    -1,    99,
   100,   101,   102,   103,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,
    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,   148,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    71,    -1,
    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
     3,    -1,    -1,    -1,     7,    -1,    -1,    -1,    -1,     3,
    -1,    94,    -1,     7,    17,    18,    19,    20,    21,    22,
    23,    24,    25,    17,    18,    19,    20,    21,    22,    23,
    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,    -1,
    -1,    54,    -1,    -1,    -1,    -1,    -1,   140,    -1,    -1,
    54,    -1,    -1,   146,    -1,   148,    69,    -1,    71,    -1,
    73,    -1,    -1,    -1,    -1,    -1,    -1,    71,    81,    73,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    94,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,     9,
    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,   131,    29,
    -1,    -1,    -1,    -1,    34,    35,    36,   131,    38,    39,
    -1,    -1,    -1,   146,    -1,   148,    -1,    47,    -1,    49,
    -1,    -1,   146,    53,   148,    -1,    56,    57,    58,    59,
    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    -1,    -1,
    -1,    -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
    -1,    -1,    -1,    83,    -1,    85,    86,    87,    -1,    -1,
    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    10,    11,    12,
    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
   130,    -1,    -1,    -1,    27,    -1,    29,    -1,   138,    -1,
   140,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
    -1,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    27,
    -1,    29,    -1,    -1,    -1,   138,    34,    35,    36,    -1,
    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,     3,   112,   113,    -1,     7,     8,     9,
    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,    -1,
    -1,    -1,   130,   131,    -1,    -1,    -1,    27,    -1,    29,
   138,    31,    -1,    -1,    34,    35,    36,    -1,    38,    39,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,    59,
    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    68,    -1,
    -1,    -1,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
    -1,    -1,    -1,    83,    -1,    85,    86,    87,    -1,    -1,
    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,    99,
   100,   101,   102,   103,    -1,    -1,    -1,    -1,     3,    -1,
    -1,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
   130,   131,    27,    -1,    29,    -1,    -1,    -1,   138,    34,
    35,    36,    -1,    38,    39,    -1,    -1,    42,    -1,    -1,
    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,    53,    -1,
    -1,    56,    57,    58,    59,    -1,    -1,    -1,    -1,    64,
    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    74,
    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    83,    -1,
    85,    86,    87,    -1,    -1,    -1,    91,    -1,    93,    -1,
    -1,    -1,    -1,    -1,    99,   100,   101,   102,   103,    -1,
    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,     8,
     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   130,    -1,   132,    27,    -1,
    29,    -1,   137,   138,    -1,    34,    35,    36,    -1,    38,
    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,    58,
    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,    -1,
    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    -1,
    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,    -1,
    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,    -1,
    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,   130,    -1,   132,    27,    -1,    29,    -1,   137,   138,
    -1,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    51,    -1,
    53,    -1,    -1,    56,    57,    58,    59,    -1,    61,    -1,
    -1,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    27,
    -1,    29,    -1,    -1,    -1,   138,    34,    35,    36,    -1,
    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   130,    -1,    27,    -1,    29,    -1,    -1,   137,
   138,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
    -1,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    27,
    -1,    29,    -1,    -1,   137,   138,    34,    35,    36,    -1,
    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   130,    -1,    27,    -1,    29,    -1,    -1,    -1,
   138,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
    -1,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,   104,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    27,
    -1,    29,    -1,    -1,    -1,   138,    34,    35,    36,    -1,
    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
    -1,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
     3,    -1,    -1,    -1,     7,     8,     9,    -1,    -1,    -1,
    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,   130,    -1,    27,    -1,    29,    -1,    -1,    -1,
   138,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    47,    -1,    49,    -1,    -1,    -1,
    53,    -1,    -1,    56,    57,    58,    59,    -1,    -1,    -1,
    -1,    64,    65,    -1,    67,    -1,    -1,    -1,    -1,    -1,
    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
    83,    -1,    85,    86,    87,    -1,    -1,    -1,    91,    -1,
    93,    -1,    -1,    -1,    -1,    -1,    99,   100,   101,   102,
   103,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,     7,
     8,     9,    -1,    -1,    -1,    -1,    -1,    15,    16,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    27,
    -1,    29,    -1,    -1,    -1,   138,    34,    35,    36,    -1,
    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,    57,
    58,    59,    -1,    -1,    -1,    -1,    64,    65,    -1,    67,
    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,
    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    86,    87,
    -1,    -1,    -1,    91,    -1,    93,    -1,    -1,    -1,    -1,
    -1,    99,   100,   101,   102,   103,    -1,    10,    11,    12,
    13,    14,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    34,   130,    36,    -1,    38,    39,    -1,    -1,    -1,
   138,    -1,    -1,    -1,    47,    48,    49,    -1,    -1,    -1,
    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    71,    -1,
    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    81,    -1,
    -1,    -1,    85,    86,    87,    10,    11,    12,    13,    14,
    -1,    94,    17,    96,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
    -1,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    47,    48,    49,    -1,    -1,    -1,    53,    54,
    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    64,
    -1,    66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,
    -1,    76,    77,    -1,    -1,    -1,    81,    -1,    -1,    -1,
    85,    86,    87,    -1,    -1,    -1,    -1,    -1,    -1,    94,
    -1,    96,    -1,    -1,    -1,    -1,    -1,    10,    11,    12,
    13,    14,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    34,    -1,    36,    -1,    38,    39,   132,    -1,    -1,
    -1,   136,    -1,   138,    47,    48,    49,    -1,    -1,    -1,
    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    71,    -1,
    -1,    74,    -1,    76,    77,    -1,    -1,    -1,    81,    -1,
    -1,    -1,    85,    86,    87,    -1,    -1,    -1,    -1,    -1,
    -1,    94,    -1,    96,    -1,    -1,    -1,    -1,    -1,    10,
    11,    12,    13,    14,    -1,    -1,    17,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    34,    -1,    36,    -1,    38,    39,   132,
    -1,    -1,    -1,   136,    -1,   138,    47,    48,    49,    -1,
    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
    71,    -1,    -1,    74,    -1,    76,    77,    -1,    -1,    -1,
    81,    -1,    -1,    -1,    85,    86,    87,    -1,    -1,    -1,
    -1,    -1,    -1,    94,    -1,    96,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,   136,    -1,   138
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not __GNUC__ */
#if HAVE_ALLOCA_H
#include <alloca.h>
#else /* not HAVE_ALLOCA_H */
#ifdef _AIX
 #pragma alloca
#else /* not _AIX */
char *alloca ();
#endif /* not _AIX */
#endif /* not HAVE_ALLOCA_H */
#endif /* not __GNUC__ */

extern int yylex();
extern void yyerror();

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = (short)yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 427 "asn_grammar.y"
{
	Module = new ModuleDefinition(yyvsp[-5].sval, yyvsp[-4].slst, (Tag::Mode)yyvsp[-2].ival);
	ReferenceTokenContext = TYPEREFERENCE;
      ;
    break;}
case 3:
#line 436 "asn_grammar.y"
{
	  yyval.slst = yyvsp[-1].slst;
	;
    break;}
case 4:
#line 440 "asn_grammar.y"
{
	  yyval.slst = new PStringList;
	;
    break;}
case 5:
#line 447 "asn_grammar.y"
{
	yyval.slst = new PStringList;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 6:
#line 452 "asn_grammar.y"
{
	yyvsp[0].slst->InsertAt(0, yyvsp[-1].sval);
	yyval.slst = yyvsp[0].slst;
      ;
    break;}
case 8:
#line 461 "asn_grammar.y"
{
	yyval.sval = new PString(PString::Unsigned, (int)yyvsp[0].ival);
      ;
    break;}
case 10:
#line 469 "asn_grammar.y"
{
	delete yyvsp[-3].sval;
	yyval.sval = new PString(PString::Unsigned, (int)yyvsp[-1].ival);
      ;
    break;}
case 11:
#line 477 "asn_grammar.y"
{
	yyval.ival = Tag::Explicit;
      ;
    break;}
case 12:
#line 481 "asn_grammar.y"
{
	yyval.ival = Tag::Implicit;
      ;
    break;}
case 13:
#line 485 "asn_grammar.y"
{
	yyval.ival = Tag::Automatic;
      ;
    break;}
case 14:
#line 489 "asn_grammar.y"
{
	yyval.ival = Tag::Explicit;
      ;
    break;}
case 19:
#line 511 "asn_grammar.y"
{
	Module->SetExports(yyvsp[0].tlst);
      ;
    break;}
case 20:
#line 515 "asn_grammar.y"
{
	Module->SetExportAll();
      ;
    break;}
case 27:
#line 540 "asn_grammar.y"
{
	CurrentImportList = yyvsp[-1].tlst;
	ReferenceTokenContext = MODULEREFERENCE;
      ;
    break;}
case 28:
#line 545 "asn_grammar.y"
{
	if (!HasObjectTypeMacro) {
	  HasObjectTypeMacro = yyvsp[-3].tlst->GetValuesIndex(SearchType("OBJECT-TYPE")) != P_MAX_INDEX;
	  if (HasObjectTypeMacro)
	    PError << "Info: including OBJECT-TYPE macro" << endl;
	}
	Module->AddImport(new ImportModule(yyvsp[0].sval, yyvsp[-3].tlst));
	ReferenceTokenContext = TYPEREFERENCE;
	CurrentImportList = NULL;
      ;
    break;}
case 29:
#line 560 "asn_grammar.y"
{
	ReferenceTokenContext = TYPEREFERENCE;
        BraceTokenContext = OID_BRACE;
      ;
    break;}
case 30:
#line 565 "asn_grammar.y"
{
        BraceTokenContext = '{';
	delete yyvsp[0].vval;
      ;
    break;}
case 33:
#line 576 "asn_grammar.y"
{
	yyval.vval = NULL;
      ;
    break;}
case 34:
#line 583 "asn_grammar.y"
{
	yyval.vval = new DefinedValue(yyvsp[0].sval);
      ;
    break;}
case 35:
#line 587 "asn_grammar.y"
{
	yyval.vval = new DefinedValue(yyvsp[0].sval);
      ;
    break;}
case 36:
#line 596 "asn_grammar.y"
{
	yyval.tlst = new TypesList;
	yyval.tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 37:
#line 601 "asn_grammar.y"
{
	yyvsp[0].tlst->Append(yyvsp[-2].tval);
	yyval.tlst = yyvsp[0].tlst;
      ;
    break;}
case 38:
#line 610 "asn_grammar.y"
{
	yyval.tval = new ImportedType(yyvsp[0].sval, FALSE);
      ;
    break;}
case 52:
#line 641 "asn_grammar.y"
{
	yyvsp[0].tval->SetName(yyvsp[-1].sval);
	Module->AddType(yyvsp[0].tval);
	IdentifierTokenContext = yyvsp[0].tval->GetIdentifierTokenContext();
	BraceTokenContext = yyvsp[0].tval->GetBraceTokenContext();
      ;
    break;}
case 53:
#line 648 "asn_grammar.y"
{
	IdentifierTokenContext = IDENTIFIER;
	BraceTokenContext = '{';
      ;
    break;}
case 54:
#line 661 "asn_grammar.y"
{
	yyvsp[0].tval->SetName(yyvsp[-2].sval);
	Module->AddType(yyvsp[0].tval);
      ;
    break;}
case 66:
#line 685 "asn_grammar.y"
{ ;
    break;}
case 82:
#line 713 "asn_grammar.y"
{
	yyval.tval = new DefinedType(yyvsp[0].sval, FALSE);
      ;
    break;}
case 83:
#line 717 "asn_grammar.y"
{
	yyval.tval = new DefinedType(yyvsp[0].sval,
			     DummyParameters != NULL &&
			     DummyParameters->GetValuesIndex(*yyvsp[0].sval) != P_MAX_INDEX);
      ;
    break;}
case 85:
#line 729 "asn_grammar.y"
{
	*yyvsp[-2].sval += *yyvsp[0].sval;
	delete yyvsp[0].sval;
      ;
    break;}
case 86:
#line 738 "asn_grammar.y"
{
	yyval.tval = new BitStringType;
      ;
    break;}
case 87:
#line 742 "asn_grammar.y"
{
	yyval.tval = new BitStringType(yyvsp[-1].nlst);
      ;
    break;}
case 88:
#line 750 "asn_grammar.y"
{
	yyval.nlst = new NamedNumberList;
	yyval.nlst->Append(yyvsp[0].nval);
      ;
    break;}
case 89:
#line 755 "asn_grammar.y"
{
	yyvsp[-2].nlst->InsertAt(0, yyvsp[0].nval);
      ;
    break;}
case 90:
#line 762 "asn_grammar.y"
{
	yyval.nval = new NamedNumber(yyvsp[-3].sval, (int)yyvsp[-1].ival);
      ;
    break;}
case 91:
#line 766 "asn_grammar.y"
{
	yyval.nval = new NamedNumber(yyvsp[-3].sval, ((DefinedValue*)yyvsp[-1].vval)->GetReference());
	delete yyvsp[-1].vval;
      ;
    break;}
case 92:
#line 775 "asn_grammar.y"
{
	yyval.tval = new BooleanType;
      ;
    break;}
case 95:
#line 788 "asn_grammar.y"
{
	yyval.tval = new BMPStringType;
      ;
    break;}
case 96:
#line 792 "asn_grammar.y"
{
	yyval.tval = new GeneralStringType;
      ;
    break;}
case 97:
#line 796 "asn_grammar.y"
{
	yyval.tval = new GraphicStringType;
      ;
    break;}
case 98:
#line 800 "asn_grammar.y"
{
	yyval.tval = new IA5StringType;
      ;
    break;}
case 99:
#line 804 "asn_grammar.y"
{
	yyval.tval = new ISO646StringType;
      ;
    break;}
case 100:
#line 808 "asn_grammar.y"
{
	yyval.tval = new NumericStringType;
      ;
    break;}
case 101:
#line 812 "asn_grammar.y"
{
	yyval.tval = new PrintableStringType;
      ;
    break;}
case 102:
#line 816 "asn_grammar.y"
{
	yyval.tval = new TeletexStringType;
      ;
    break;}
case 103:
#line 820 "asn_grammar.y"
{
	yyval.tval = new T61StringType;
      ;
    break;}
case 104:
#line 824 "asn_grammar.y"
{
	yyval.tval = new UniversalStringType;
      ;
    break;}
case 105:
#line 828 "asn_grammar.y"
{
	yyval.tval = new VideotexStringType;
      ;
    break;}
case 106:
#line 832 "asn_grammar.y"
{
	yyval.tval = new VisibleStringType;
      ;
    break;}
case 107:
#line 840 "asn_grammar.y"
{
	yyval.tval = new UnrestrictedCharacterStringType;
      ;
    break;}
case 108:
#line 848 "asn_grammar.y"
{
	yyval.tval = yyvsp[-1].tval;
      ;
    break;}
case 109:
#line 855 "asn_grammar.y"
{
	yyval.tval = new ChoiceType(yyvsp[0].tlst);
      ;
    break;}
case 110:
#line 859 "asn_grammar.y"
{
	yyval.tval = new ChoiceType(yyvsp[-2].tlst, TRUE);
      ;
    break;}
case 111:
#line 863 "asn_grammar.y"
{
	yyval.tval = new ChoiceType(yyvsp[-4].tlst, TRUE, yyvsp[0].tlst);
      ;
    break;}
case 112:
#line 870 "asn_grammar.y"
{
	yyval.tlst = new TypesList;
	yyval.tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 113:
#line 875 "asn_grammar.y"
{
	yyvsp[-2].tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 115:
#line 888 "asn_grammar.y"
{
	yyvsp[0].tval->SetName(yyvsp[-1].sval);
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 116:
#line 893 "asn_grammar.y"
{
	PError << StdError(Warning) << "unnamed field." << endl;
	yyvsp[0].tval->SetName(new PString(PString::Printf, "_unnamed%u", UnnamedFieldCount++));
      ;
    break;}
case 117:
#line 903 "asn_grammar.y"
{
	yyval.tval = new EmbeddedPDVType;
      ;
    break;}
case 118:
#line 911 "asn_grammar.y"
{
	yyval.tval = yyvsp[-1].tval;
      ;
    break;}
case 119:
#line 918 "asn_grammar.y"
{
	yyval.tval = new EnumeratedType(yyvsp[0].nlst, FALSE, NULL);
      ;
    break;}
case 120:
#line 922 "asn_grammar.y"
{
	yyval.tval = new EnumeratedType(yyvsp[-4].nlst, TRUE, NULL);
      ;
    break;}
case 121:
#line 926 "asn_grammar.y"
{
	yyval.tval = new EnumeratedType(yyvsp[-6].nlst, TRUE, yyvsp[0].nlst);
      ;
    break;}
case 122:
#line 933 "asn_grammar.y"
{
	yyval.nlst = new NamedNumberList;
	yyval.nlst->Append(yyvsp[0].nval);
      ;
    break;}
case 123:
#line 938 "asn_grammar.y"
{
	yyvsp[-2].nlst->Append(yyvsp[0].nval);
        PINDEX sz = yyvsp[-2].nlst->GetSize();
        if (sz > 1)
          yyvsp[0].nval->SetAutoNumber((*yyvsp[-2].nlst)[sz-2]);
	yyval.nlst = yyvsp[-2].nlst;
      ;
    break;}
case 124:
#line 949 "asn_grammar.y"
{
	yyval.nval = new NamedNumber(yyvsp[0].sval);
      ;
    break;}
case 126:
#line 958 "asn_grammar.y"
{
	yyval.tval = new ExternalType;
      ;
    break;}
case 127:
#line 966 "asn_grammar.y"
{
	yyval.tval = new AnyType(NULL);
      ;
    break;}
case 128:
#line 970 "asn_grammar.y"
{
	yyval.tval = new AnyType(yyvsp[0].sval);
      ;
    break;}
case 130:
#line 983 "asn_grammar.y"
{
	yyval.tval = new IntegerType;
      ;
    break;}
case 131:
#line 987 "asn_grammar.y"
{
	yyval.tval = new IntegerType(yyvsp[-1].nlst);
      ;
    break;}
case 132:
#line 995 "asn_grammar.y"
{
	yyval.tval = new NullType;
      ;
    break;}
case 133:
#line 1003 "asn_grammar.y"
{
	yyval.tval = new ObjectClassFieldType(yyvsp[-2].sval, yyvsp[0].sval);
      ;
    break;}
case 134:
#line 1011 "asn_grammar.y"
{
	yyval.tval = new ObjectIdentifierType;
      ;
    break;}
case 135:
#line 1018 "asn_grammar.y"
{
	yyval.tval = new OctetStringType;
      ;
    break;}
case 136:
#line 1026 "asn_grammar.y"
{
	yyval.tval = new RealType;
      ;
    break;}
case 137:
#line 1034 "asn_grammar.y"
{
	yyval.tval = yyvsp[-1].tval;
      ;
    break;}
case 138:
#line 1038 "asn_grammar.y"
{
	yyval.tval = new SequenceType(NULL, FALSE, NULL);
      ;
    break;}
case 139:
#line 1042 "asn_grammar.y"
{
	yyval.tval = new SequenceType(NULL, TRUE, NULL);
      ;
    break;}
case 140:
#line 1049 "asn_grammar.y"
{
	yyval.tval = new SequenceType(yyvsp[0].tlst, FALSE, NULL);
      ;
    break;}
case 141:
#line 1053 "asn_grammar.y"
{
	yyval.tval = new SequenceType(yyvsp[-2].tlst, TRUE, NULL);
      ;
    break;}
case 142:
#line 1057 "asn_grammar.y"
{
	yyval.tval = new SequenceType(yyvsp[-4].tlst, TRUE, yyvsp[0].tlst);
      ;
    break;}
case 143:
#line 1061 "asn_grammar.y"
{
	yyval.tval = new SequenceType(NULL, TRUE, yyvsp[0].tlst);
      ;
    break;}
case 144:
#line 1068 "asn_grammar.y"
{
	yyval.tlst = new TypesList;
	yyval.tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 145:
#line 1073 "asn_grammar.y"
{
	yyvsp[-2].tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 147:
#line 1081 "asn_grammar.y"
{
	yyvsp[-1].tval->SetOptional();
      ;
    break;}
case 148:
#line 1085 "asn_grammar.y"
{
	IdentifierTokenContext = yyvsp[-1].tval->GetIdentifierTokenContext();
      ;
    break;}
case 149:
#line 1089 "asn_grammar.y"
{
	IdentifierTokenContext = IDENTIFIER;
	yyvsp[-3].tval->SetDefaultValue(yyvsp[0].vval);
      ;
    break;}
case 150:
#line 1094 "asn_grammar.y"
{
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 151:
#line 1102 "asn_grammar.y"
{
	yyval.tval = new SequenceOfType(yyvsp[0].tval, NULL);
      ;
    break;}
case 152:
#line 1110 "asn_grammar.y"
{
	yyval.tval = new SetType((SequenceType*)yyvsp[-1].tval);
      ;
    break;}
case 153:
#line 1114 "asn_grammar.y"
{
	yyval.tval = new SetType;
      ;
    break;}
case 154:
#line 1122 "asn_grammar.y"
{
	yyval.tval = new SetOfType(yyvsp[0].tval, NULL);
      ;
    break;}
case 155:
#line 1130 "asn_grammar.y"
{
	yyvsp[0].tval->SetTag(yyvsp[-1].tagv.tagClass, yyvsp[-1].tagv.tagNumber, Module->GetDefaultTagMode());
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 156:
#line 1135 "asn_grammar.y"
{
	yyvsp[0].tval->SetTag(yyvsp[-2].tagv.tagClass, yyvsp[-2].tagv.tagNumber, Tag::Implicit);
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 157:
#line 1140 "asn_grammar.y"
{
	yyvsp[0].tval->SetTag(yyvsp[-2].tagv.tagClass, yyvsp[-2].tagv.tagNumber, Tag::Explicit);
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 158:
#line 1148 "asn_grammar.y"
{
	yyval.tagv.tagClass = (Tag::Type)yyvsp[-2].ival;
	yyval.tagv.tagNumber = (int)yyvsp[-1].ival;
      ;
    break;}
case 160:
#line 1157 "asn_grammar.y"
{
	if (PIsDescendant(yyvsp[0].vval, IntegerValue))
	  yyval.ival = *(IntegerValue*)yyvsp[0].vval;
	else
	  PError << StdError(Fatal) << "incorrect value type." << endl;
      ;
    break;}
case 161:
#line 1167 "asn_grammar.y"
{
	yyval.ival = Tag::Universal;
      ;
    break;}
case 162:
#line 1171 "asn_grammar.y"
{
	yyval.ival = Tag::Application;
      ;
    break;}
case 163:
#line 1175 "asn_grammar.y"
{
	yyval.ival = Tag::Private;
      ;
    break;}
case 164:
#line 1179 "asn_grammar.y"
{
	yyval.ival = Tag::ContextSpecific;
      ;
    break;}
case 165:
#line 1187 "asn_grammar.y"
{
	yyval.tval = new SelectionType(yyvsp[-2].sval, yyvsp[0].tval);
      ;
    break;}
case 166:
#line 1195 "asn_grammar.y"
{
	yyval.tval = new GeneralizedTimeType;
      ;
    break;}
case 167:
#line 1199 "asn_grammar.y"
{
	yyval.tval = new UTCTimeType;
      ;
    break;}
case 168:
#line 1203 "asn_grammar.y"
{
	yyval.tval = new ObjectDescriptorType;
      ;
    break;}
case 169:
#line 1211 "asn_grammar.y"
{ ;
    break;}
case 172:
#line 1224 "asn_grammar.y"
{ ;
    break;}
case 173:
#line 1226 "asn_grammar.y"
{ ;
    break;}
case 175:
#line 1239 "asn_grammar.y"
{
	yyvsp[-1].tval->AddConstraint(yyvsp[0].cons);
      ;
    break;}
case 177:
#line 1247 "asn_grammar.y"
{
	yyval.tval = new SetOfType(yyvsp[0].tval, yyvsp[-2].cons);
      ;
    break;}
case 178:
#line 1251 "asn_grammar.y"
{
	yyval.tval = new SetOfType(yyvsp[0].tval, new Constraint(yyvsp[-2].elmt));
      ;
    break;}
case 179:
#line 1255 "asn_grammar.y"
{
	yyval.tval = new SequenceOfType(yyvsp[0].tval, yyvsp[-2].cons);
      ;
    break;}
case 180:
#line 1259 "asn_grammar.y"
{
	yyval.tval = new SequenceOfType(yyvsp[0].tval, new Constraint(yyvsp[-2].elmt));
      ;
    break;}
case 181:
#line 1266 "asn_grammar.y"
{
	yyval.cons = yyvsp[-2].cons;
      ;
    break;}
case 184:
#line 1279 "asn_grammar.y"
{
	yyval.vval = yyvsp[0].vval;
      ;
    break;}
case 185:
#line 1283 "asn_grammar.y"
{
	yyval.vval = NULL;
      ;
    break;}
case 186:
#line 1291 "asn_grammar.y"
{
	yyval.vval = new IntegerValue(yyvsp[0].ival);
      ;
    break;}
case 188:
#line 1296 "asn_grammar.y"
{
	delete yyvsp[-2].tval;
        PError << StdError(Warning) << "Typed exception unsupported" << endl;
	yyval.vval = yyvsp[0].vval;
      ;
    break;}
case 189:
#line 1306 "asn_grammar.y"
{
	yyval.cons = new Constraint(yyvsp[0].elst, FALSE, NULL);
      ;
    break;}
case 190:
#line 1310 "asn_grammar.y"
{
	yyval.cons = new Constraint(yyvsp[-4].elst, TRUE, NULL);
      ;
    break;}
case 191:
#line 1314 "asn_grammar.y"
{
	yyval.cons = new Constraint(NULL, TRUE, yyvsp[0].elst);
      ;
    break;}
case 192:
#line 1318 "asn_grammar.y"
{
	yyval.cons = new Constraint(yyvsp[-5].elst, TRUE, yyvsp[0].elst);
      ;
    break;}
case 194:
#line 1327 "asn_grammar.y"
{
	yyval.elst = new ConstraintElementList;
	yyval.elst->Append(new ConstrainAllConstraintElement(yyvsp[0].elmt));
      ;
    break;}
case 195:
#line 1336 "asn_grammar.y"
{
	yyval.elst = new ConstraintElementList;
	yyval.elst->Append(new ElementListConstraintElement(yyvsp[0].elst));
      ;
    break;}
case 196:
#line 1341 "asn_grammar.y"
{
	yyvsp[-2].elst->Append(new ElementListConstraintElement(yyvsp[0].elst));
      ;
    break;}
case 197:
#line 1348 "asn_grammar.y"
{
	yyval.elst = new ConstraintElementList;
	yyval.elst->Append(yyvsp[0].elmt);
      ;
    break;}
case 198:
#line 1353 "asn_grammar.y"
{
	yyvsp[-2].elst->Append(yyvsp[0].elmt);
      ;
    break;}
case 200:
#line 1361 "asn_grammar.y"
{
	yyvsp[-1].elmt->SetExclusions(yyvsp[0].elmt);
      ;
    break;}
case 201:
#line 1368 "asn_grammar.y"
{
	yyval.elmt = yyvsp[0].elmt;
      ;
    break;}
case 208:
#line 1387 "asn_grammar.y"
{
	yyval.elmt = new ElementListConstraintElement(yyvsp[-1].elst);
      ;
    break;}
case 209:
#line 1395 "asn_grammar.y"
{
	yyval.elmt = new SingleValueConstraintElement(yyvsp[0].vval);
      ;
    break;}
case 210:
#line 1399 "asn_grammar.y"
{
	yyval.elmt = new SubTypeConstraintElement(yyvsp[0].tval);
      ;
    break;}
case 215:
#line 1411 "asn_grammar.y"
{
	yyval.elmt = new ValueRangeConstraintElement(yyvsp[-3].vval, yyvsp[0].vval);
      ;
    break;}
case 219:
#line 1424 "asn_grammar.y"
{
	yyval.vval = yyvsp[0].vval;
      ;
    break;}
case 221:
#line 1432 "asn_grammar.y"
{
	yyval.vval = new MinValue;
      ;
    break;}
case 223:
#line 1440 "asn_grammar.y"
{
	yyval.vval = new MaxValue;
      ;
    break;}
case 224:
#line 1447 "asn_grammar.y"
{
	yyval.elmt = new FromConstraintElement(yyvsp[0].cons);
      ;
    break;}
case 225:
#line 1454 "asn_grammar.y"
{
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 230:
#line 1469 "asn_grammar.y"
{
	yyval.elmt = new SizeConstraintElement(yyvsp[0].cons);
      ;
    break;}
case 231:
#line 1477 "asn_grammar.y"
{
	yyval.elmt = new WithComponentConstraintElement(NULL, yyvsp[0].cons, WithComponentConstraintElement::Default);
      ;
    break;}
case 232:
#line 1481 "asn_grammar.y"
{
	yyval.elmt = yyvsp[0].elmt;
      ;
    break;}
case 233:
#line 1488 "asn_grammar.y"
{
	yyval.elmt = new InnerTypeConstraintElement(yyvsp[-1].elst, FALSE);
      ;
    break;}
case 234:
#line 1492 "asn_grammar.y"
{
	yyval.elmt = new InnerTypeConstraintElement(yyvsp[-1].elst, TRUE);
      ;
    break;}
case 235:
#line 1499 "asn_grammar.y"
{
	yyval.elst = new ConstraintElementList;
	yyval.elst->Append(yyvsp[0].elmt);
      ;
    break;}
case 236:
#line 1504 "asn_grammar.y"
{
	yyvsp[0].elst->Append(yyvsp[-2].elmt);
	yyval.elst = yyvsp[0].elst;
      ;
    break;}
case 237:
#line 1512 "asn_grammar.y"
{
	yyval.elmt = new WithComponentConstraintElement(yyvsp[-1].sval, NULL, (int)yyvsp[0].ival);
      ;
    break;}
case 238:
#line 1516 "asn_grammar.y"
{
	yyval.elmt = new WithComponentConstraintElement(yyvsp[-2].sval, yyvsp[-1].cons, (int)yyvsp[0].ival);
      ;
    break;}
case 239:
#line 1523 "asn_grammar.y"
{
	yyval.ival = WithComponentConstraintElement::Present;
      ;
    break;}
case 240:
#line 1527 "asn_grammar.y"
{
	yyval.ival = WithComponentConstraintElement::Absent;
      ;
    break;}
case 241:
#line 1531 "asn_grammar.y"
{
	yyval.ival = WithComponentConstraintElement::Optional;
      ;
    break;}
case 242:
#line 1535 "asn_grammar.y"
{
	yyval.ival = WithComponentConstraintElement::Default;
      ;
    break;}
case 245:
#line 1548 "asn_grammar.y"
{
      yyval.cons = new Constraint(yyvsp[-1].elmt);
    ;
    break;}
case 246:
#line 1555 "asn_grammar.y"
{
	yyval.elmt = new UserDefinedConstraintElement(NULL);
      ;
    break;}
case 247:
#line 1559 "asn_grammar.y"
{
	yyval.elmt = new UserDefinedConstraintElement(yyvsp[0].tlst);
      ;
    break;}
case 248:
#line 1566 "asn_grammar.y"
{
	yyvsp[0].tlst->Append(yyvsp[-2].tval);
	yyval.tlst = yyvsp[0].tlst;
      ;
    break;}
case 249:
#line 1571 "asn_grammar.y"
{
	yyval.tlst = new TypesList;
	yyval.tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 250:
#line 1579 "asn_grammar.y"
{
	yyval.tval = yyvsp[0].tval;
      ;
    break;}
case 254:
#line 1593 "asn_grammar.y"
{ yyval.cons = NULL; ;
    break;}
case 261:
#line 1616 "asn_grammar.y"
{ ;
    break;}
case 262:
#line 1621 "asn_grammar.y"
{ ;
    break;}
case 263:
#line 1626 "asn_grammar.y"
{ ;
    break;}
case 264:
#line 1632 "asn_grammar.y"
{ ;
    break;}
case 270:
#line 1646 "asn_grammar.y"
{
	yyval.sval = ConcatNames(yyvsp[-2].sval, '.', yyvsp[0].sval);
      ;
    break;}
case 271:
#line 1653 "asn_grammar.y"
{
	yyval.sval = new PString("TYPE-IDENTIFIER");
      ;
    break;}
case 272:
#line 1657 "asn_grammar.y"
{
	yyval.sval = new PString("ABSTRACT-SYNTAX");
      ;
    break;}
case 283:
#line 1684 "asn_grammar.y"
{ ;
    break;}
case 287:
#line 1695 "asn_grammar.y"
{ ;
    break;}
case 293:
#line 1711 "asn_grammar.y"
{ ;
    break;}
case 294:
#line 1716 "asn_grammar.y"
{ ;
    break;}
case 298:
#line 1727 "asn_grammar.y"
{ ;
    break;}
case 299:
#line 1732 "asn_grammar.y"
{ ;
    break;}
case 303:
#line 1743 "asn_grammar.y"
{ ;
    break;}
case 317:
#line 1779 "asn_grammar.y"
{ ;
    break;}
case 328:
#line 1794 "asn_grammar.y"
{ ;
    break;}
case 342:
#line 1813 "asn_grammar.y"
{ ;
    break;}
case 343:
#line 1818 "asn_grammar.y"
{ ;
    break;}
case 344:
#line 1824 "asn_grammar.y"
{ ;
    break;}
case 345:
#line 1830 "asn_grammar.y"
{ ;
    break;}
case 346:
#line 1832 "asn_grammar.y"
{ ;
    break;}
case 347:
#line 1837 "asn_grammar.y"
{ ;
    break;}
case 349:
#line 1848 "asn_grammar.y"
{
	yyval.sval = ConcatNames(yyvsp[-2].sval, '.', yyvsp[0].sval);
      ;
    break;}
case 356:
#line 1866 "asn_grammar.y"
{ ;
    break;}
case 357:
#line 1872 "asn_grammar.y"
{ ;
    break;}
case 358:
#line 1874 "asn_grammar.y"
{ ;
    break;}
case 359:
#line 1924 "asn_grammar.y"
{ ;
    break;}
case 361:
#line 1935 "asn_grammar.y"
{ ;
    break;}
case 362:
#line 1937 "asn_grammar.y"
{ ;
    break;}
case 363:
#line 1942 "asn_grammar.y"
{ ;
    break;}
case 370:
#line 1966 "asn_grammar.y"
{
	DummyParameters = yyvsp[0].slst;
      ;
    break;}
case 371:
#line 1970 "asn_grammar.y"
{
	DummyParameters = NULL;
	yyvsp[0].tval->SetName(yyvsp[-4].sval);
	yyvsp[0].tval->SetParameters(yyvsp[-3].slst);
	Module->AddType(yyvsp[0].tval);
      ;
    break;}
case 372:
#line 1980 "asn_grammar.y"
{ ;
    break;}
case 373:
#line 1985 "asn_grammar.y"
{ ;
    break;}
case 374:
#line 1990 "asn_grammar.y"
{ ;
    break;}
case 375:
#line 1995 "asn_grammar.y"
{ ;
    break;}
case 376:
#line 2000 "asn_grammar.y"
{ ;
    break;}
case 377:
#line 2005 "asn_grammar.y"
{
	yyval.slst = yyvsp[-1].slst;
      ;
    break;}
case 378:
#line 2012 "asn_grammar.y"
{
	yyval.slst = yyvsp[-2].slst;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 379:
#line 2017 "asn_grammar.y"
{
	yyval.slst = new PStringList;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 380:
#line 2025 "asn_grammar.y"
{
	yyval.sval = yyvsp[0].sval;
      ;
    break;}
case 382:
#line 2033 "asn_grammar.y"
{ ;
    break;}
case 383:
#line 2035 "asn_grammar.y"
{ ;
    break;}
case 384:
#line 2041 "asn_grammar.y"
{
	yyval.tval = new ParameterizedType(yyvsp[-1].sval, yyvsp[0].tlst);
      ;
    break;}
case 387:
#line 2054 "asn_grammar.y"
{
	yyval.tlst = yyvsp[-1].tlst;
      ;
    break;}
case 388:
#line 2061 "asn_grammar.y"
{
	yyvsp[-2].tlst->Append(yyvsp[0].tval);
	yyval.tlst = yyvsp[-2].tlst;
      ;
    break;}
case 389:
#line 2066 "asn_grammar.y"
{
	yyval.tlst = new TypesList;
	yyval.tlst->Append(yyvsp[0].tval);
      ;
    break;}
case 391:
#line 2075 "asn_grammar.y"
{ ;
    break;}
case 392:
#line 2077 "asn_grammar.y"
{ ;
    break;}
case 393:
#line 2079 "asn_grammar.y"
{ ;
    break;}
case 394:
#line 2093 "asn_grammar.y"
{
	IdentifierTokenContext = yyvsp[0].tval->GetIdentifierTokenContext();
	BraceTokenContext = yyvsp[0].tval->GetBraceTokenContext();
	NullTokenContext = NULL_VALUE;
      ;
    break;}
case 395:
#line 2099 "asn_grammar.y"
{
	yyvsp[0].vval->SetValueName(yyvsp[-4].sval);
	Module->AddValue(yyvsp[0].vval);
	IdentifierTokenContext = IDENTIFIER;
	BraceTokenContext = '{';
	NullTokenContext = NULL_TYPE;
      ;
    break;}
case 402:
#line 2125 "asn_grammar.y"
{
	yyval.vval = new IntegerValue(yyvsp[0].ival);
      ;
    break;}
case 408:
#line 2147 "asn_grammar.y"
{
	yyval.vval = new DefinedValue(yyvsp[0].sval);
      ;
    break;}
case 409:
#line 2151 "asn_grammar.y"
{
	yyval.vval = new DefinedValue(yyvsp[0].sval);
      ;
    break;}
case 411:
#line 2160 "asn_grammar.y"
{
	*yyvsp[-2].sval += *yyvsp[0].sval;
	delete yyvsp[0].sval;
      ;
    break;}
case 412:
#line 2169 "asn_grammar.y"
{
        IdentifierTokenContext = OID_IDENTIFIER;
      ;
    break;}
case 413:
#line 2173 "asn_grammar.y"
{
	yyval.vval = new ObjectIdentifierValue(yyvsp[-1].slst);
	IdentifierTokenContext = IDENTIFIER;
      ;
    break;}
case 414:
#line 2188 "asn_grammar.y"
{
	yyval.slst = new PStringList;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 415:
#line 2193 "asn_grammar.y"
{
	yyvsp[0].slst->InsertAt(0, yyvsp[-1].sval);
	yyval.slst = yyvsp[0].slst;
      ;
    break;}
case 417:
#line 2202 "asn_grammar.y"
{
	yyval.sval = new PString(PString::Unsigned, (int)yyvsp[0].ival);
      ;
    break;}
case 418:
#line 2206 "asn_grammar.y"
{
	delete yyvsp[-3].sval;
	yyval.sval = yyvsp[-1].sval;
      ;
    break;}
case 419:
#line 2214 "asn_grammar.y"
{
	yyval.sval = new PString(PString::Unsigned, (int)yyvsp[0].ival);
      ;
    break;}
case 422:
#line 2224 "asn_grammar.y"
{
	yyval.vval = new OctetStringValue(yyvsp[0].sval);
      ;
    break;}
case 423:
#line 2228 "asn_grammar.y"
{
	yyval.vval = new OctetStringValue(yyvsp[0].sval);
      ;
    break;}
case 424:
#line 2235 "asn_grammar.y"
{
	yyval.vval = new BitStringValue(yyvsp[0].sval);
      ;
    break;}
case 425:
#line 2239 "asn_grammar.y"
{
	yyval.vval = new BitStringValue(yyvsp[0].sval);
      ;
    break;}
case 426:
#line 2243 "asn_grammar.y"
{
	yyval.vval = new BitStringValue(yyvsp[-1].slst);
      ;
    break;}
case 427:
#line 2247 "asn_grammar.y"
{
	yyval.vval = new BitStringValue;
      ;
    break;}
case 428:
#line 2255 "asn_grammar.y"
{
	yyval.slst = new PStringList;
      ;
    break;}
case 429:
#line 2259 "asn_grammar.y"
{
	// Look up $3
	yyvsp[-2].slst->SetAt(yyvsp[-2].slst->GetSize(), 0);
      ;
    break;}
case 430:
#line 2268 "asn_grammar.y"
{
	yyval.vval = new BooleanValue(TRUE);
      ;
    break;}
case 431:
#line 2272 "asn_grammar.y"
{
	yyval.vval = new BooleanValue(FALSE);
      ;
    break;}
case 433:
#line 2287 "asn_grammar.y"
{
	yyval.vval = new CharacterStringValue(yyvsp[0].sval);
      ;
    break;}
case 437:
#line 2297 "asn_grammar.y"
{
	yyval.vval = new CharacterStringValue(yyvsp[-1].slst);
      ;
    break;}
case 438:
#line 2304 "asn_grammar.y"
{
	yyval.slst = new PStringList;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 439:
#line 2309 "asn_grammar.y"
{
	yyvsp[-2].slst->Append(yyvsp[0].sval);
      ;
    break;}
case 441:
#line 2317 "asn_grammar.y"
{
	PError << StdError(Warning) << "DefinedValue in string unsupported" << endl;
      ;
    break;}
case 442:
#line 2324 "asn_grammar.y"
{
	if (yyvsp[-7].ival != 0 || yyvsp[-5].ival != 0 || yyvsp[-3].ival > 255 || yyvsp[-1].ival > 255)
	  PError << StdError(Warning) << "Illegal value in Character Quadruple" << endl;
	yyval.vval = new CharacterValue((BYTE)yyvsp[-7].ival, (BYTE)yyvsp[-5].ival, (BYTE)yyvsp[-3].ival, (BYTE)yyvsp[-1].ival);
      ;
    break;}
case 443:
#line 2333 "asn_grammar.y"
{
	if (yyvsp[-3].ival > 255 || yyvsp[-1].ival > 255)
	  PError << StdError(Warning) << "Illegal value in Character Tuple" << endl;
	yyval.vval = new CharacterValue((BYTE)yyvsp[-3].ival, (BYTE)yyvsp[-1].ival);
      ;
    break;}
case 444:
#line 2343 "asn_grammar.y"
{
	yyvsp[0].vval->SetValueName(yyvsp[-2].sval);
	yyval.vval = yyvsp[0].vval;
      ;
    break;}
case 445:
#line 2352 "asn_grammar.y"
{
	yyval.vval = new NullValue;
      ;
    break;}
case 448:
#line 2365 "asn_grammar.y"
{
	yyval.vval = new RealValue(0);
      ;
    break;}
case 449:
#line 2375 "asn_grammar.y"
{
	yyval.vval = new RealValue(0);
      ;
    break;}
case 450:
#line 2379 "asn_grammar.y"
{
	yyval.vval = new RealValue(0);
      ;
    break;}
case 451:
#line 2387 "asn_grammar.y"
{
	yyval.vval = new SequenceValue(yyvsp[-1].vlst);
      ;
    break;}
case 452:
#line 2391 "asn_grammar.y"
{
	yyval.vval = new SequenceValue;
      ;
    break;}
case 453:
#line 2398 "asn_grammar.y"
{
	yyval.vlst = new ValuesList;
	yyval.vlst->Append(yyvsp[0].vval);
      ;
    break;}
case 454:
#line 2403 "asn_grammar.y"
{
	yyvsp[-2].vlst->Append(yyvsp[0].vval);
      ;
    break;}
case 455:
#line 2410 "asn_grammar.y"
{
	yyvsp[0].vval->SetValueName(yyvsp[-1].sval);
	yyval.vval = yyvsp[0].vval;
      ;
    break;}
case 457:
#line 2467 "asn_grammar.y"
{ ;
    break;}
case 461:
#line 2488 "asn_grammar.y"
{
	PError << StdError(Warning) << "MACRO unsupported" << endl;
      ;
    break;}
case 462:
#line 2495 "asn_grammar.y"
{
	InMacroContext = TRUE;
      ;
    break;}
case 463:
#line 2499 "asn_grammar.y"
{
	InMacroContext = FALSE;
      ;
    break;}
case 464:
#line 2503 "asn_grammar.y"
{;
    break;}
case 465:
#line 2505 "asn_grammar.y"
{;
    break;}
case 475:
#line 2555 "asn_grammar.y"
{;
    break;}
case 476:
#line 2557 "asn_grammar.y"
{;
    break;}
case 477:
#line 2559 "asn_grammar.y"
{;
    break;}
case 492:
#line 2587 "asn_grammar.y"
{;
    break;}
case 493:
#line 2592 "asn_grammar.y"
{;
    break;}
case 494:
#line 2600 "asn_grammar.y"
{
	InMIBContext = TRUE;
      ;
    break;}
case 495:
#line 2610 "asn_grammar.y"
{
	IdentifierTokenContext = OID_IDENTIFIER;
      ;
    break;}
case 496:
#line 2614 "asn_grammar.y"
{
	Module->AddMIB(new MibObject(yyvsp[-15].sval, yyvsp[-11].tval, (MibObject::Access)yyvsp[-9].ival, (MibObject::Status)yyvsp[-7].ival, yyvsp[-6].sval, yyvsp[-5].sval, yyvsp[-4].slst, yyvsp[-3].vval, yyvsp[0].vval));
	InMIBContext = FALSE;
	IdentifierTokenContext = IDENTIFIER;
      ;
    break;}
case 497:
#line 2623 "asn_grammar.y"
{
	yyval.ival = MibObject::read_only;
      ;
    break;}
case 498:
#line 2627 "asn_grammar.y"
{
	yyval.ival = MibObject::read_write;
      ;
    break;}
case 499:
#line 2631 "asn_grammar.y"
{
	yyval.ival = MibObject::write_only;
      ;
    break;}
case 500:
#line 2635 "asn_grammar.y"
{
	yyval.ival = MibObject::not_accessible;
      ;
    break;}
case 501:
#line 2642 "asn_grammar.y"
{
	yyval.ival = MibObject::mandatory;
      ;
    break;}
case 502:
#line 2646 "asn_grammar.y"
{
	yyval.ival = MibObject::optional;
      ;
    break;}
case 503:
#line 2650 "asn_grammar.y"
{
	yyval.ival = MibObject::obsolete;
      ;
    break;}
case 504:
#line 2654 "asn_grammar.y"
{
	yyval.ival = MibObject::deprecated;
      ;
    break;}
case 505:
#line 2661 "asn_grammar.y"
{
	yyval.sval = yyvsp[0].sval;
      ;
    break;}
case 506:
#line 2665 "asn_grammar.y"
{
	yyval.sval = NULL;
      ;
    break;}
case 507:
#line 2672 "asn_grammar.y"
{
	yyval.sval = yyvsp[0].sval;
      ;
    break;}
case 508:
#line 2676 "asn_grammar.y"
{
	yyval.sval = NULL;
      ;
    break;}
case 509:
#line 2683 "asn_grammar.y"
{
	yyval.slst = yyvsp[-1].slst;
      ;
    break;}
case 510:
#line 2687 "asn_grammar.y"
{
	yyval.slst = NULL;
      ;
    break;}
case 511:
#line 2694 "asn_grammar.y"
{
	yyval.slst = new PStringList;
	yyval.slst->Append(yyvsp[0].sval);
      ;
    break;}
case 512:
#line 2699 "asn_grammar.y"
{
	yyvsp[-2].slst->Append(yyvsp[0].sval);
      ;
    break;}
case 515:
#line 2711 "asn_grammar.y"
{
	yyval.vval = yyvsp[-1].vval;
      ;
    break;}
case 516:
#line 2715 "asn_grammar.y"
{
	yyval.vval = NULL;
      ;
    break;}
case 517:
#line 2722 "asn_grammar.y"
{
	InMIBContext = TRUE;
	IdentifierTokenContext = OID_IDENTIFIER;
      ;
    break;}
case 518:
#line 2731 "asn_grammar.y"
{
	Module->AddMIB(new MibTrap(yyvsp[-9].sval, yyvsp[-5].vval, yyvsp[-4].vlst, yyvsp[-3].sval, yyvsp[-2].sval, yyvsp[0].vval));
	IdentifierTokenContext = IDENTIFIER;
	InMIBContext = FALSE;
      ;
    break;}
case 519:
#line 2740 "asn_grammar.y"
{
	yyval.vlst = yyvsp[-1].vlst;
      ;
    break;}
case 520:
#line 2744 "asn_grammar.y"
{
	yyval.vlst = NULL;
      ;
    break;}
case 521:
#line 2751 "asn_grammar.y"
{
	yyval.vlst = new ValuesList;
	yyval.vlst->Append(yyvsp[0].vval);
      ;
    break;}
case 522:
#line 2756 "asn_grammar.y"
{
	yyvsp[-2].vlst->Append(yyvsp[0].vval);
      ;
    break;}
case 528:
#line 2797 "asn_grammar.y"
{
	yyval.tval = new ImportedType(yyvsp[-2].sval, TRUE);
      ;
    break;}
case 529:
#line 2805 "asn_grammar.y"
{
	yyval.nlst = new NamedNumberList;
	yyval.nlst->Append(yyvsp[0].nval);
      ;
    break;}
case 530:
#line 2810 "asn_grammar.y"
{
	yyvsp[-2].nlst->Append(yyvsp[0].nval);
      ;
    break;}
case 531:
#line 2817 "asn_grammar.y"
{
	yyval.nval = new NamedNumber(yyvsp[-3].sval, (int)yyvsp[-1].ival);
      ;
    break;}
case 532:
#line 2821 "asn_grammar.y"
{
	yyval.nval = new NamedNumber(yyvsp[-3].sval, ((DefinedValue*)yyvsp[-1].vval)->GetReference());
	delete yyvsp[-1].vval;
      ;
    break;}
case 534:
#line 2831 "asn_grammar.y"
{
	yyval.ival = -yyvsp[0].ival;
      ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 2838 "asn_grammar.y"
