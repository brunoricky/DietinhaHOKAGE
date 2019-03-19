#include "Data.h"
#include <stdio.h>
#include <iostream>
#include <ilcplex/ilocplex.h>

void solve(Data& data);

int main(int argc, char** argv)
{
   if(argc != 2)
   {
      printf("Usage:\n./bin instance\n");
      return 0;
   }

   Data data;
   data.readData(argv[1]);

   solve(data);

   return 0;
}

void solve(Data& data)
{
   IloEnv env;
   IloModel modelo(env);

   IloIntVarArray x(env, data.getNItems(), 0, IloInfinity);
   
   //adiciona a variavel x ao modelo
   for(int i = 0; i <  data.getNItems(); i++)
   {
	   char var[100];
	   sprintf(var, "X(%d)", i);
	   x[i].setName(var);
	   modelo.add(x[i]);
   }

   //fim das variaveis
   ///////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////
   //Criando a Função Objetivo (FO) 
   IloExpr sumX(env);
   for(int i = 0; i < data.getNItems(); i++)
   {
	sumX += x[i]*data.getCost(i);
   }

   // Adicionando a FO
   modelo.add(IloMinimize(env, sumX));
   //////////////////////////////////////////////////////////

   ////////////////////////////////////////////////////////
   //Restricoes
	
   //Restricoes (1): Restricoes carb
   IloExpr SumC(env);
   IloExpr SumP(env);
   IloExpr SumF(env);
	
   for(int i = 0; i < data.getNItems(); i++) 
   {
	SumC += x[i]*data.getCarb(i);	
   }
   modelo.add(SumC == 250);

   //Restricoes (2): Restricoes prot
   for(int i = 0; i < data.getNItems(); i++) 
   {
	SumP += x[i]*data.getProt(i);
   }
   modelo.add(SumP == 150);

   //Restricoes (3): Restricoes fat
   for(int i = 0; i < data.getNItems(); i++) 
   {
	SumF += x[i]*data.getFat(i);
   }
   modelo.add(SumF == 60);

   //fim das restricoes
   ////////////////////////////////////////////////////////

   //resolve o modelo
   IloCplex bpp(modelo);
   bpp.setParam(IloCplex::TiLim,2*60*60);
   bpp.setParam(IloCplex::Threads, 1);
   bpp.exportModel("modelo.lp");
   
   try
   {
      bpp.solve();
   }
   catch(IloException& e)
   {
	std::cout << e;
   }

   std::cout << "status:" << bpp.getStatus() << std::endl;
   std::cout << "custo total:" << bpp.getObjValue() << std::endl;
   for(int i = 0; i < data.getNItems(); i++) 
   {
	
        if(bpp.getValue(x[i]) > 0.001)
	{
		  std::cout << bpp.getValue(x[i]) << "g do item " << i << std::endl;
	}
   }
}
