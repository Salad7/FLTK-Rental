
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
Fl_Hold_Browser rent(550,80,200,200,"Rent");
Fl_Hold_Browser detail(780,80,200,200,"Out for detail");
Fl_Hold_Browser repair(1040,80,200,200,"Out for repair");

Fl_Button rentVehicle(40,320,200,30,"Rent vehicle");
Fl_Button returnVehicle(290,320,200,30,"Return vehicle");
Fl_Button returnVehicleProblem(550,320,200,30,"Return Vehicle (With problem)");
Fl_Button repairVehicle(780,320,200,30,"Repair vehicle");
Fl_Button detailVehicle(1040,320,200,30,"Detail vehicle");

Fl_Input personName(100,400,300,30,"First Name");
Fl_Input personLastName(100,450,300,30,"Last Name");
Fl_Button addCustomer(100,500,300,30,"Add customer");

Fl_Input vehYear(600,400,200,30,"Vehicle Year");
Fl_Input vehMake(600,450,200,30,"Vehicle Make");
Fl_Input vehModel(600,500,200,30,"Vehicle Model");
Fl_Button addVehicle(600,550,200,30,"Add Vehicle");
//Search
Fl_Input searchPerson(920,400,200,30,"Search by Name: ");
Fl_Button searchPersonButton(1140,400,100,30,"Search By Name");
Fl_Input searchByVehicle(920,450,200,30,"Search By Vehicle");
Fl_Button searchVehicleButton(1140,450,100,30,"Search By Name");
Fl_Output results(920,500,325,100);





void customerCallback(Fl_Widget* widget, void* v){
  //Set customerID to -1
  Fl_Hold_Browser* customer = (Fl_Hold_Browser*)v;
  int cSize = customer->size();
  std::string concat = (std::string) personName.value() + " " +(std::string) personLastName.value();
  customer->insert(0,concat.c_str());
}
void vehicleCallBack(Fl_Widget* widget, void* v){
  //Set customerID to -1
  Fl_Hold_Browser* vehicle = (Fl_Hold_Browser*)v;
  int cSize = vehicle->size();
  std::string concat = (std::string)(std::string) vehMake.value() + " | "+ vehModel.value() + " | " +(std::string) vehYear.value();
  vehicle->insert(0,concat.c_str());
}
//This call back works when a user and a vehicle are ready to be rented
void availableCallBack(Fl_Widget* widget, void* v){
  //Set customerID to -1
  int cSize = customer.size();
  int customerFound = -1;
  int vehicleFound = -1;
  int vSize = avail.size();
  //Looping through the customer list
  for(int i = 0; i < cSize; i++){
    //If the customer is selected
    if(customer.selected(i+1)){
      //Update customerFound to store position of customer
      customerFound = (i+1);
      //Break from for loop
      i = cSize+1;
    }
  }
  for(int i = 0; i < vSize; i++){
    if(avail.selected(i+1)){
      vehicleFound = (i+1);
      i = vSize+1;
    }
  }
  std::string postSelect = (std::string) avail.text(vehicleFound) + " --- "+customer.text(customerFound);
  avail.select(vehicleFound,0);
  customer.select(customerFound,0);
  rent.insert(0,postSelect.c_str());
}

//void returnVehicleCallBack

int main(int argc, char **argv) {
  addCustomer.callback(customerCallback,&customer);
  addVehicle.callback(vehicleCallBack,&avail);
  rentVehicle.callback(availableCallBack,&customer);

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
