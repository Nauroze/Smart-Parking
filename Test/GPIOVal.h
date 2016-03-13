/*
 * GPIOVal.h
 *
 *  Created on: Feb 7, 2015
 *      Author: mahmoudkhalaf
 */

#ifndef GPIOVAL_H_
#define GPIOVAL_H_

class GPIOVal {
public:
	GPIOVal(int GPIOPin, int Val);
	virtual ~GPIOVal();
private:
	char setValue[4],GPIOValue[64];
};

#endif /* GPIOVAL_H_ */
