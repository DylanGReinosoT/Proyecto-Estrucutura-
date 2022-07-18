#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>

int c = 1, cc;

class arbol
{
 private:
	struct nodetype
	{
		int  info;
		nodetype *izq, *der;
	} *r;
	// es el que se utilisa como mensaje
	char msg[80];
 public:
	arbol() { r = NULL; }
	~arbol();
	void destructor(nodetype *);
	void insertar(int x);
	void extraer(int x);
	void extraer(int x, nodetype *&r);
	nodetype *maketree(int x);

	void preorden();
	void inorden();
	void postorden();
	void preorden(nodetype *);
	void inorden(nodetype *);
	void postorden(nodetype *);

	void despliega();
	void despliega(nodetype *);
};

arbol::~arbol()
{
	destructor(r);
}

void arbol::destructor(nodetype *p)
{
	if(p->izq) destructor(p->izq);
	if(p->der) destructor(p->der);
	delete p;
}

void arbol::insertar(int x)
{
	nodetype *p = r;

	if(r == NULL)
		r = maketree(x);
	else
	{
		do
		{
			if(x == p->info) break;
			if(x > p->info)
			{
				if(!p->der) p->der = maketree(x);
				p = p->der;
			}
			if(x < p->info)
			{
				if(!p->izq) p->izq = maketree(x);
				p = p->izq;
			}
		} while(1);
	}
}

void arbol::extraer(int x)
{
	nodetype *p = r, *q = r;
	if(r)
	{
		if(x == r->info)
		{
			if(!p->der)
				r = r->izq;
			else
			{
				p = p->der;
				r = p;
				while(p->izq) p = p->izq;
				p->izq = q->izq;
			}
			delete q;
		}
		else extraer(x, r);
	}
}

void arbol::extraer(int x, nodetype * &r)
{
	if(r)
	{
		if(x > r->info)
		{
			extraer(x, r->der);
		}
		else if(x < r->info)
			extraer(x, r->izq);
		else
		{
			nodetype *p = r, *q = r;
			if(r->der)
			{
				p = p->der;
				r = p;
				while(p->izq) p = p->izq;
				p->izq = q->izq;
			} else r = r->izq;
			if(q) delete q;
		}
	}
}

nodetype* arbol::maketree(int x)
{
	nodetype *nuevo = new nodetype;

	if(nuevo)
	{
		nuevo->info = x;
		nuevo->izq  = NULL;
		nuevo->der  = NULL;
	}
	return nuevo;
}

void arbol::despliega()
{
	if(r)
		despliega(r);
}

int y1, y2, d;

void arbol::despliega(nodetype *r)
{
	if(r->izq)
	{
		c++;d=1;
		despliega(r->izq);
	}

	y2 = c * 2 + 3;
	gotoxy(cc += 3, y2);

	circle((cc*10),(y2*10)+30, 14);
	//transforma el int info a el char msg[80]
	sprintf(msg, "%d",r->info);
	//imprime a msg[80] en el centro del circulo
	outtextxy(((cc*10)-3),(y2*10)+25,msg);
		//if(d=1)
		//{
	line((cc*10),(y2*10)+15,cc,y2);
		//}
		//gotoxy(cc, y2);

	//cout << r->info;//setw(3) <<r->info;

	if(r->der)
	{
		c++;d=0;
		despliega(r->der);
	}
	c--;
}

void arbol::preorden()
{
 if(r)
	   preorden(r);
}

void arbol::inorden()
{
 if(r)
	  inorden(r);
}

void arbol::postorden()
{
 if(r)
	  postorden(r);
}

void arbol::preorden(nodetype *r)
{
 if(r!=NULL)
 {
  cout<<r->info<<endl;
  preorden(r->izq);
  preorden(r->der);
 }
}

void arbol::inorden(nodetype *r)
{
 if(r!=NULL)
 {
  inorden(r->izq);
  cout<<r->info<<endl;
  inorden(r->der);
 }
}

void arbol::postorden(nodetype *r)
{
 if(r!=NULL)
 {
  postorden(r->izq);
  postorden(r->der);
  cout<<r->info<<endl;
 }
}


void main()
{

	int gdriver = DETECT, gmode, errorcode;
								//no olvides cambiar el
								//directorio al que tenias
								// y no te olvide de los karmas
								//att: neoexe ... Que viva Paipa!!
	initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

	cleardevice();

	arbol x;
	char car, opcion;
	int numero, i;
	clrscr();
	do
	{
		delay(100);
		gotoxy(1,1);
		cout << "\n a)Agregar  b)Borrar  c)Salir  d)Recorridos ==>>Opcion?: ";
		cin  >> car;

		if(car == 'a' || car == 'A')
		{
			cout << "\nEscriba el numero que desea dar de alta: ";
			cin  >> numero;
			x.insertar(numero);

			cleardevice();
			x.despliega();
			c  = 1;
			cc = 0;
		}
		if(car == 'b' || car == 'B')
		{
			cout << "\nEscriba el numero que desea dar de baja: ";
			cin  >> numero;
			x.extraer(numero);

			cleardevice();
			x.despliega();
			c  = 1;
			cc = 0;
		}
		if(car=='c'||car=='C')
		{exit(0);}
		if(car == 'd' || car == 'D')
		{
			gotoxy(3,3);
			cout<<"Elige tu opcion:";
			cout<<"\na) Preorden\nb) Inorden\nc) Postorden";
			cin>>opcion;
			switch(opcion)
			{
			 case 'a':
			 case 'A': cleardevice();
				   x.preorden();
				   break;
			 case 'b':
			 case 'B': cleardevice();
				   x.inorden();
				   break;
			 case 'c':
			 case 'C': cleardevice();
				   x.postorden();
				   break;
			}
		}
	} while(car != 'c' && car != 'C');
	getch();
	closegraph();
}

