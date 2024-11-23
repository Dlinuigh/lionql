/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    DECIMAL = 259,                 /* DECIMAL  */
    BINARY = 260,                  /* BINARY  */
    STRING = 261,                  /* STRING  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    A_IDENT = 263,                 /* A_IDENT  */
    G_IDENT = 264,                 /* G_IDENT  */
    USE = 265,                     /* USE  */
    SELECT = 266,                  /* SELECT  */
    INSERT = 267,                  /* INSERT  */
    UPDATE = 268,                  /* UPDATE  */
    DELETE = 269,                  /* DELETE  */
    CREATE = 270,                  /* CREATE  */
    ALTER = 271,                   /* ALTER  */
    DROP = 272,                    /* DROP  */
    FROM = 273,                    /* FROM  */
    WHERE = 274,                   /* WHERE  */
    INTO = 275,                    /* INTO  */
    AS = 276,                      /* AS  */
    TO = 277,                      /* TO  */
    BETWEEN = 278,                 /* BETWEEN  */
    ADD = 279,                     /* ADD  */
    USING = 280,                   /* USING  */
    ON = 281,                      /* ON  */
    VALUES = 282,                  /* VALUES  */
    RENAME = 283,                  /* RENAME  */
    MODIFY = 284,                  /* MODIFY  */
    SET = 285,                     /* SET  */
    NULL_VAL = 286,                /* NULL_VAL  */
    PRIMARY = 287,                 /* PRIMARY  */
    KEY = 288,                     /* KEY  */
    DEFAULT = 289,                 /* DEFAULT  */
    AUTO_INCREMENT = 290,          /* AUTO_INCREMENT  */
    FOREIGN = 291,                 /* FOREIGN  */
    AFTER = 292,                   /* AFTER  */
    BEFORE = 293,                  /* BEFORE  */
    BEGIN_SYM = 294,               /* BEGIN_SYM  */
    END_SYM = 295,                 /* END_SYM  */
    REFERENCES = 296,              /* REFERENCES  */
    INT = 297,                     /* INT  */
    TINYINT = 298,                 /* TINYINT  */
    SMALLINT = 299,                /* SMALLINT  */
    BIGINT = 300,                  /* BIGINT  */
    DECIMAL_TYPE = 301,            /* DECIMAL_TYPE  */
    NUMERIC = 302,                 /* NUMERIC  */
    FLOAT = 303,                   /* FLOAT  */
    DOUBLE = 304,                  /* DOUBLE  */
    CHAR = 305,                    /* CHAR  */
    VARCHAR = 306,                 /* VARCHAR  */
    TEXT = 307,                    /* TEXT  */
    DATE = 308,                    /* DATE  */
    TIME = 309,                    /* TIME  */
    DATETIME = 310,                /* DATETIME  */
    YEAR = 311,                    /* YEAR  */
    TIMESTAMP = 312,               /* TIMESTAMP  */
    CURRENT_TIMESTAMP = 313,       /* CURRENT_TIMESTAMP  */
    BOOL = 314,                    /* BOOL  */
    BLOB = 315,                    /* BLOB  */
    BINARY_TYPE = 316,             /* BINARY_TYPE  */
    VARBINARY = 317,               /* VARBINARY  */
    ENUM = 318,                    /* ENUM  */
    SET_FUNC = 319,                /* SET_FUNC  */
    UUID = 320,                    /* UUID  */
    JSON = 321,                    /* JSON  */
    XML = 322,                     /* XML  */
    IN = 323,                      /* IN  */
    OUT = 324,                     /* OUT  */
    INOUT = 325,                   /* INOUT  */
    INNER = 326,                   /* INNER  */
    LEFT = 327,                    /* LEFT  */
    JOIN = 328,                    /* JOIN  */
    ORDER = 329,                   /* ORDER  */
    BY = 330,                      /* BY  */
    LIMIT = 331,                   /* LIMIT  */
    ASC = 332,                     /* ASC  */
    DESC = 333,                    /* DESC  */
    OFFSET = 334,                  /* OFFSET  */
    WITH = 335,                    /* WITH  */
    DELIMITER = 336,               /* DELIMITER  */
    CALL = 337,                    /* CALL  */
    FOR = 338,                     /* FOR  */
    EACH = 339,                    /* EACH  */
    CHECK = 340,                   /* CHECK  */
    GROUP = 341,                   /* GROUP  */
    ROW = 342,                     /* ROW  */
    DECLARE = 343,                 /* DECLARE  */
    DATABASE = 344,                /* DATABASE  */
    TABLE = 345,                   /* TABLE  */
    VIEW = 346,                    /* VIEW  */
    INDEX = 347,                   /* INDEX  */
    COLUMN = 348,                  /* COLUMN  */
    PROCEDURE = 349,               /* PROCEDURE  */
    TRIGGER = 350,                 /* TRIGGER  */
    IS = 351,                      /* IS  */
    AND = 352,                     /* AND  */
    OR = 353,                      /* OR  */
    NOT = 354,                     /* NOT  */
    END = 355,                     /* END  */
    LEFT_FUNC = 356,               /* LEFT_FUNC  */
    AVG_FUNC = 357,                /* AVG_FUNC  */
    IF = 358,                      /* IF  */
    THEN = 359,                    /* THEN  */
    SIGNAL = 360,                  /* SIGNAL  */
    MESSAGE_TEXT = 361,            /* MESSAGE_TEXT  */
    SQLSTATE = 362,                /* SQLSTATE  */
    DELIMITER_END = 363,           /* DELIMITER_END  */
    GT = 364,                      /* GT  */
    LT = 365,                      /* LT  */
    EQ = 366,                      /* EQ  */
    GE = 367,                      /* GE  */
    LE = 368,                      /* LE  */
    COMMA = 369,                   /* COMMA  */
    LPAREN = 370,                  /* LPAREN  */
    RPAREN = 371,                  /* RPAREN  */
    MATCH_ANY = 372,               /* MATCH_ANY  */
    NEW = 373,                     /* NEW  */
    OLD = 374,                     /* OLD  */
    NOW = 375                      /* NOW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

  char* str;

#line 188 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
