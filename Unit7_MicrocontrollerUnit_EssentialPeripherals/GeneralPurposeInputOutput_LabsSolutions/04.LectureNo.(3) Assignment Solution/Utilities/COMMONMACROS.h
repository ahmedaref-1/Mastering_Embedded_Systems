/*
 * COMMONMACROS.h
 *
 *  Created on: Jul 22, 2023
 *      Author: ahmed
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_
/*********************************************
 *                                           *
 *        GENRIC MACROS DEFINITION           *
 *                                           *
 *********************************************/
/**********************************************
 *      BIT MANIPULATION MACROS DEFINITION    *
 * ********************************************/
#define SET_BIT(REG,BIT)        (REG |=(1<<BIT))
#define CLEAR_BIT(REG,BIT)      (REG &=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT)     (REG ^=(1<<BIT))
#define BIT_IS_SET(REG,BIT)     (REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT)   (!(REG & (1<<BIT)))

/**********************************************
 *         VALUES MACROS DEFINITION           *
 * ********************************************/
#define TRUE        1U
#define FALSE       0U
#define HIGH		1U
#define LOW 		1U
/*********** GLOBAL ENUM DEFINITION **********/
typedef enum{
	SUCCESS,
	FAIL
}Return_t;

#endif /* COMMONMACROS_H_ */
