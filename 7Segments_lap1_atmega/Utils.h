/*
 * Utils.h
 *
 * Created: 9/14/2023 6:48:26 AM
 *  Author: 10
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(reg_addr,bit) (reg.addr |= (1<<bit))
#define CLEAR_BIT(reg_addr,bit) (reg.addr &= ~(1<<bit))
#define READ_BIT(reg_addr,bit) ((reg.addr>>bit)&1)
#define TOGGLE_BIT(reg_addr,bit) (reg.addr ^= (1<<bit))







#endif /* UTILS_H_ */