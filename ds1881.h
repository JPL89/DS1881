// @File		D1804.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		17/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef D1804_H
#define D1804_H

#define DS1881_SLA_W 0x50
#define DS1881_SLA_R 0x51

#define DS1881_POT0_REGISTER 0x00
#define DS1881_POT1_REGISTER 0x40
#define DS1881_CONF_REGISTER 0x80

void DS1881_Write(unsigned char reg, unsigned char data)
{
    Wire_Start();
	Wire_Write(DS1881_SLA_W);
    Wire_Write((unsigned char)(reg | data)); 
	Wire_Stop();
}

void D1881_Read(unsigned char *p0, unsigned char *p1, unsigned char *cf)
{    
    Wire_Start();
	Wire_Write(DS1881_SLA_R);
    *p0 = Wire_Ack(); 
    *p1 = Wire_Ack(); 
    *cf = Wire_Nack(); 
	Wire_Stop();
}

#endif 
