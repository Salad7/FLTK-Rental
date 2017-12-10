
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Table.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>

Fl_Double_Window win(1500, 1200, "Simple Table");
// Fl_Output customerTitle(0,40,100,100,0);
// customerTitle.value("Customers");
Fl_Hold_Browser customer(40,80,200,200,"Customers");
Fl_Hold_Browser avail(290,80,200,200,"Available Vehicles");
Fl_Hold_Browser rent(540,80,200,200,"Rent");
Fl_Hold_Browser detail(790,80,200,200,"Out for detail");
Fl_Hold_Browser repair(1040,80,200,200,"Out for repair");

Fl_Button rentVehicle(40,300,200,30,"Rent vehicle");
Fl_Button returnVehicle(290,300,200,30,"Return vehicle");
Fl_Button returnVehicleProblem(550,300,200,30,"Return Vehicle (With problem)");
Fl_Button repairVehicle(780,300,200,30,"Repair vehicle");
Fl_Button detailVehicle(1040,300,200,30,"Detail vehicle");

Fl_Input personName(100,400,300,30,"First Name");
Fl_Input personLastName(100,450,300,30,"Last Name");
Fl_Button addCustomer(100,500,300,30,"Add customer");

Fl_Input vehName(600,400,200,30,"Vehicle Name");
Fl_Input vehMake(600,450,200,30,"Vehicle Make");
Fl_Input vehModel(600,500,200,30,"Vehicle Model");
Fl_Input vehYear(600,550,200,30,"Vehicle Year");
Fl_Button addVehicle(600,600,200,30,"Add Vehicle");

void customerCallback(Fl_Widget* widget, void* v){
  //Set customerID to -1
  Fl_Hold_Browser* customer = (Fl_Hold_Browser*)v;
  int cSize = customer->size();
  std::string concat = (std::string) personName.value() + " " +(std::string) personLastName.value();
  customer->insert(0,concat.c_str());
}

int main(int argc, char **argv) {
  addCustomer.callback(customerCallback,&customer);
  avail.insert(0,"avail");
  rent.insert(0,"rent");
  detail.insert(0,"detail");
  repair.insert(0,"repair");
  customer.insert(0,"customer");
  win.end();
//  win.resizable(browser);
  win.show(argc,argv);
  return(Fl::run());
}
