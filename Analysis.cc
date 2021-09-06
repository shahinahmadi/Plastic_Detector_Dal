// This script takes the output of GEARS analysis and puts the data to a proper histogrsm
//Author: Shahin Ahmadi
//Date: Sep/7/2021


#include "TFile.h"
#include "TTree.h"

void Analysis() {

  // opening the file
  TFile *f = TFile::Open("gears.root");

  //Creating histogram
  TH1F *h1 = new TH1F("h1", ";Energy;Counts", 200,0, 2000);
   
  TTree* tree = (TTree*) f->Get("t");


  
  //Taking et(energy total) branch from the tree and project it to the histogram
  tree->Project("h1", "et");


  //Setting the titles for the histogram and the axis of the histogram
  
  h1->GetXaxis()->SetTitle("Gamma Energy(ev)");
  h1->GetYaxis()->SetTitle("Counts");
  h1->SetTitle("Response of PVT to 2 MeV cosine  gamma ray");
  h1->SetTitleOffset(1);
  
  h1->GetXaxis()->CenterTitle();
  h1->GetYaxis()->CenterTitle();
  gStyle->SetTitleFontSize(0.03);
  gStyle->SetOptStat();

  
  //Removing the Statistics box from the plot
   h1->SetStats(0);

  
  //Plotting
  h1->Draw();               

}
