#ifndef _DATA_H_
#define _DATA_H_

#include <vector>
#include <stdio.h>

class Data
{
   private:

      int n_items;
      std::vector<double> carb;
      std::vector<double> prot;
      std::vector<double> fat;
      std::vector<double> cost;	

   public:

      void readData(char* filePath);

      int getNItems();

      double getCarb(unsigned int indexC);

      double getProt(unsigned int indexP);

      double getFat(unsigned int indexF);

      double getCost(unsigned int indexCo);	
};

#endif

