#include "main.h"
void GPIO_Init(void);
void delayms(uint16_t ms);
int main(void)
{
  GPIO_Init();
  int i = 1;
  while (1)
  {
    i ++;
    if(!(GPIOC->IDR & 1<<13))          //Light blinks when button 1 pressed (C13)
    {
      GPIOA->ODR ^= 1<<5;      //Toggle bit A5.
      delayms(i);
    }
    if(i>100)
    {
      i = 1;
    }
  }
}

void GPIO_Init(void)
{
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;

  /*Configure GPIO pin : PC13 */
  GPIOC->MODER &= ~ (3<<13*2);                      //PC13 set to input
  GPIOC->PUPDR &= ~ (3<<13*2);                      //no Pull-up or pull down

  /*Configure GPIO pin : PA5 */
  GPIOA->BSRR = 1<<(5+16);                       //Resets PA5 at bit 21
  GPIOA->MODER &= ~(3<<(5*2));                   //PA5 set to output (mode 1)  - Step 1
  GPIOA->MODER |= (1<<(5*2));                    //PA5 set to output (mode 1)  - Step 2
  GPIOA->OSPEEDR &= ~(3<<(5*2));                 //PA5 set to low speed (low-current) 
  GPIOA->PUPDR &= ~(3<<(5*2));                   //PA5 set to no pull-up or down 
}

void delayms(uint16_t ms) //close to milliseconds
{
  volatile uint32_t time = 0;
  while(++time < 400 * ms);
}