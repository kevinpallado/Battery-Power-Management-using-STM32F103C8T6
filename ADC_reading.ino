float ADC_movingAverage(int adc_val, int battery_cell){
  // cell 1
  if(battery_cell == 0){
    firstCell_ADCreading[0] = adc_val;
    ADCsum = 0;
    for(int counter = 0; counter < ADCsample; counter++){ // sum all values in array
      ADCsum += firstCell_ADCreading[counter];
    }
    float ADCreference = ADCsum / ADCsample;
  
    for(int counterMove = ( ADCsample - 1); counterMove >= 0; counterMove--){ // moving values of array forward
      if(counterMove <= 0) firstCell_ADCreading[0] = 0;
      else firstCell_ADCreading[counterMove] = firstCell_ADCreading[counterMove-1]; // this is where the values move forward
    }
    return ADCreference;
  }

  // cell 2
  else if(battery_cell == 1){
    secondCell_ADCreading[0] = adc_val;
    ADCsum = 0;
    for(int counter = 0; counter < ADCsample; counter++){ // sum all values in array
      ADCsum += secondCell_ADCreading[counter];
    }
    float ADCreference = ADCsum / ADCsample;
  
    for(int counterMove = ( ADCsample - 1); counterMove >= 0; counterMove--){ // moving values of array forward
      if(counterMove <= 0) secondCell_ADCreading[0] = 0;
      else secondCell_ADCreading[counterMove] = secondCell_ADCreading[counterMove-1]; // this is where the values move forward
    }
    return ADCreference;
  }
  // cell 3
  else if(battery_cell == 2){
    thirdCell_ADCreading[0] = adc_val;
    ADCsum = 0;
    for(int counter = 0; counter < ADCsample; counter++){ // sum all values in array
      ADCsum += thirdCell_ADCreading[counter];
    }
    float ADCreference = ADCsum / ADCsample;
  
    for(int counterMove = ( ADCsample - 1); counterMove >= 0; counterMove--){ // moving values of array forward
      if(counterMove <= 0) thirdCell_ADCreading[0] = 0;
      else thirdCell_ADCreading[counterMove] = thirdCell_ADCreading[counterMove-1]; // this is where the values move forward
    }
    return ADCreference;
  }
  // cell 4
  else if(battery_cell == 3){
    fourthCell_ADCreading[0] = adc_val;
    ADCsum = 0;
    for(int counter = 0; counter < ADCsample; counter++){ // sum all values in array
      ADCsum += fourthCell_ADCreading[counter];
    }
    float ADCreference = ADCsum / ADCsample;
  
    for(int counterMove = ( ADCsample - 1); counterMove >= 0; counterMove--){ // moving values of array forward
      if(counterMove <= 0) fourthCell_ADCreading[0] = 0;
      else fourthCell_ADCreading[counterMove] = fourthCell_ADCreading[counterMove-1]; // this is where the values move forward
    }
    return ADCreference;
  }
}
