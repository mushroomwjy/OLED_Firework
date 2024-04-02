    #ifndef __OLEDFONT_H
    #define __OLEDFONT_H 	   
    // ------------------  ASCII字模的数据表 ------------------------ //
    // 码表从0x20~0x7e                                                //
    // 字库:  纵向取模下高位// （调用时要减512）
    // -------------------------------------------------------------- //
    
    	unsigned char F16x16[];
      const unsigned char F6x8[][6];
      const unsigned char F8X16[];
      unsigned char fireworkdata[];
    
    #endif
