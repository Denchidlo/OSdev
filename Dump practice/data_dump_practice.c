#include "stdint.h"
//Practice with bit fields 

//Case 1
/*
    //Case 1:
    typedef struct mem_bitfield_char
    {
        char b1:8;
        char b2:8;
        char b3:8;
        char b4:8;
        char b5:4;
    }field;

    field fld = {
        .b1 = 0x01,
        .b2 = 0x04,
        .b5 = 0x7
    };

    field fld2 = {
        .b1 = 0x03,
        .b2 = 0x02
    };

    //Memory dump
    //Address   | Memory field
    //0x00004000 00000000 00000000 08400000 00000000 .........@......
    //0x00004010 01040000 07030200 0000              ..........

    //Results of case 1 : here we can see that each field is 5 byte long

*/

//Case 2
/*
    //Case 2:
    typedef struct mem_bitfield_char
    {
        int b1:8;
        int b2:8;
        int b3:8;
        int b4:8;
        char b5:4;
    }field;

    field fld = {
        .b1 = 0x01,
        .b2 = 0x04,
        .b5 = 0x7
    };

    field fld2 = {
        .b1 = 0x03,
        .b2 = 0x02
    };

    //Memory dump
    //Address   | Memory field
    //0x00004000 00000000 00000000 08400000 00000000 .........@......
    //0x00004010 01040000 07000000 03020000 00000000 ................

    //Results of case 1 : it takes 2 words (int vars to keep despite data5 needs only 1 byte)

*/

//Exercise 4.8.2 from the book
/*

    typedef struct st_bit
    {
        int fld1:16;
        int fld2:24;
    }bit_struct;

    bit_struct bits = {
        .fld1 = 0x11,
        .fld2 = 0x2233
    };

    //Memory dump
    //Address   | Memory field
    //0x00004000 00000000 00000000 08400000 00000000 .........@......
    //0x00004010 11000000 33220000                   ....3"..

    //Results of exercise : we unlikely found that first field was 4 bytes in length
    //So if we have two fields with width bigger than (OP_SIZE) they'd be separated into 2 operands

*/ 

//Bitfield section end

//Strings and arrays

//Case 1
/*
    //Case 1
    uint8_t b8[2] = { 0x11, 0x22 };
    uint16_t b16[2] = { 0x1122, 0x3344 };
    uint32_t b32[2] = { 0x11223344, 0x55667788 };
    uint64_t b64[2] = { 0x1122334455667788, 0x99aabbccddeeff00 };

    //Memory dump
    //Address   | Memory field
    //0x00004010 11222211 44330000 44332211 88776655 ."".D3..D3"..wfU
    //0x00004020 88776655 44332211 00ffeedd ccbbaa99 .wfUD3".........

    //Results: here we can see 2byte alingment in the first row fo 32bit value
*/


int main(int argc, int** argv)
{
    return 0;
}