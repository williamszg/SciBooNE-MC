#define NeutrinoMode_cxx
#include "NeutrinoMode.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <math.h>
#include <stdio.h>

#define PI 3.14159265


TH1D *hMuonMomentumx = new TH1D("hMuonMomentumx", "Muon X Momentum", 500, -2500, 2500); //This is the histogram for the Muon X Momentum
TH1D *hMuonMomentumy = new TH1D("hMuonMomentumy", "Muon Y Momentum", 500, -2500, 2500); //This is the histogram for the Muon Y Momentum
TH1D *hMuonMomentumz = new TH1D("hMuonMomentumz", "Muon Z Momentum", 500, -2500, 2500); //This is the histogram for the Muon Z Momentum
TH1D *hMuonEnergy = new TH1D("hMuonEnergy", "Muon Energy", 500, 0, 5000); //This is the histogram for the Muon Energy

TH1D *hPionMomentumx = new TH1D("hPionMomentumx", "Pion X Momentum", 500, -2500, 2500); //This is the histogram for the Pion X Momentum
TH1D *hPionMomentumy = new TH1D("hPionMomentumy", "Pion Y Momentum", 500, -2500, 2500); //This is the histogram for the Pion Y Momentum
TH1D *hPionMomentumz = new TH1D("hPionMomentumz", "Pion Z Momentum", 500, -2500, 2500); //This is the histogram for the Pion Z Momentum
TH1D *hPionEnergy = new TH1D("hPionEnergy", "Pion Energy", 500, 0, 5000); //This is the histogram for the Pion Energy

TH1D *hAngles = new TH1D("hAngles", "Opening Angles", 500, 0, 2*PI); //This is the histogram for the opening angles between the muon and the pion

TH1D *h1 = new TH1D("h1", "X Vertex Distribution",100,0,3);
TH1D *h2 = new TH1D("h2", "Y Vertex Distribution",100,0,3);
TH1D *h3 = new TH1D("h3", "Z Vertex Distribution",100,0,3);

// Define a function

void NeutrinoMode::Loop()
{

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();
   int nTotalEvents = 0;
   Long64_t nbytes = 0, nb = 0;
   int mpresent = 0;
   int nMPevents = 0;
   int nMAPevents = 0;
   int nmpresent = 0;
   int nppresent = 0;
   int nmpart = 0;
   int nppart = 0;
   int tfstate = 0;
   double angle = 0;

   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      TRandom3 *rand = new TRandom3();
      TRandom3 *flat = new TRandom3();
      rand->SetSeed(jentry);
      flat->SetSeed(jentry);
      double Xpos = rand->Gaus(1.5,2.5);
      double Ypos = rand->Gaus(1.5,2.5);
      double Zpos = flat->Uniform(0,3);
      h1->Fill(Xpos);
      h2->Fill(Ypos);
      h3->Fill(Zpos);
      for(int npart = 0; npart < StdHepN; npart++)
      {

      if((StdHepPdg[npart] == 13 || StdHepPdg[npart] == -13) && StdHepStatus[npart] == 1)
         {

         mpresent = 1;
         nmpresent++;
         nmpart = npart;         

         } //<---End counting of muon in single event

      if((StdHepPdg[npart] == 211 || StdHepPdg[npart] == -211) && (mpresent == 1 && StdHepStatus[npart] == 1))
         {

         nMPevents++;
         mpresent = 0;
         nppresent++;
         nppart = npart;

         } //<---End checking for both a muon and a pion in an event

      if(StdHepStatus[npart] == 1)
         {

         tfstate++;

         } //<---End checking for the total number of final state particles coming from the interaction

      if(nmpresent == 1) //Is the total number of muons in the event one?
         {
         
         if(nppresent == 1) //Is the total number of pions in the event one?
            {

            if((npart == StdHepN - 1) && tfstate == 2) //Are there only two particles in the final state in this interaction? And are you done slewing over all of the particles in this event?
               {
               
               angle1 = acos (((StdHepP4[nppart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nppart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nppart][2]*StdHepP4[nmpart][2])) / sqrt ((((StdHepP4[nppart][0]*StdHepP4[nppart][0]) + (StdHepP4[nppart][1]*StdHepP4[nppart][1]) + (StdHepP4[nppart][2]*StdHepP4[nppart][2]))*((StdHepP4[nmpart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nmpart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nmpart][2]*StdHepP4[nmpart][2]))))); //This is the first attempt to find the angle between the momentum vectors of the muon and the pion using the brute force dot product by definition
               

               //############################################################
               //### This is a different method for the angle calculation ###
               //############################################################

               double x1 = StdHepP4[nppart][0]*StdHepP4[nmpart][0]; //x-component of dot product between muon and pion
               double y1 = StdHepP4[nppart][1]*StdHepP4[nmpart][1]; //y-component of dot product between muon and pion
               double z1 = StdHepP4[nppart][2]*StdHepP4[nmpart][2]; //z-component of dot product between muon and pion
               double x2 = StdHepP4[nmpart][0]*StdHepP4[nmpart][0]; //x-component of muon momentum magnitude
               double y2 = StdHepP4[nmpart][1]*StdHepP4[nmpart][1]; //y-component of muon momentum magnitude
               double z2 = StdHepP4[nmpart][2]*StdHepP4[nmpart][2]; //z-component of muon momentum magnitude
               double x3 = StdHepP4[nppart][0]*StdHepP4[nppart][0]; //x-component of pion momentum magnitude
               double y3 = StdHepP4[nppart][1]*StdHepP4[nppart][1]; //y-component of pion momentum magnitude
               double z3 = StdHepP4[nppart][2]*StdHepP4[nppart][2]; //z-component of pion momentum magnitude
               double dot1 = x1 + y1 + z1; //This is the dot product between the muon and pion momentum
               double mag1 = sqrt(x2 + y2 + z2); //This is the magnitude of the muon momentum
               double mag2 = sqrt(x3 + y3 + z3); //This is the magnitude of the pion momentum
               double angle2 = acos( dot1/(mag1*mag2)); //This is the second way of finding the angle between the muon and pion momentums

               //std::cout<<"Muon Z Momentum"<<StdHepP4[nmpart][2]<<std::endl;
               //std::cout<<"Pion Z Momentum"<<StdHepP4[nppart][2]<<std::endl;
               //std::cout<<std::endl;

               hPionMomentumx->Fill(StdHepP4[nppart][0] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hPionMomentumy->Fill(StdHepP4[nppart][1] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hPionMomentumz->Fill(StdHepP4[nppart][2] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hPionEnergy->Fill(StdHepP4[nppart][3] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV

               hMuonMomentumx->Fill(StdHepP4[nmpart][0] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hMuonMomentumy->Fill(StdHepP4[nmpart][1] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hMuonMomentumz->Fill(StdHepP4[nmpart][2] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV
               hMuonEnergy->Fill(StdHepP4[nmpart][3] * 1000); //Note: We multiply by 1000 to convert between GeV to MeV

               hAngles->Fill(angle2); //This fills the Opening Angles histogram with the angle between the two momentums

               nppresent = 0;
               nmpresent = 0;
               nmpart = 0;
               nppart = 0;
               nMAPevents++;
               tfstate = 0;

               }

            }

         } //<---End if statement for exclusive pion and muon presence.

      } //<---End npart for-loop

   mpresent = 0;
   nmpresent = 0;
   nppresent = 0;
   tfstate = 0;

   } //<---End jentry for-loop
   
   std::cout<<"Total Number of Simulated Events = "<<1000000<<std::endl; //Print out the total number of simulated events.
   std::cout<<"Number of Events Containing a Muon and a Pion = "<<nMPevents<<std::endl; //Print out the number of events containing a Muon and a Pion
   std::cout<<"Number of Events Containing a Muon and a Pion, exclusively = "<<nMAPevents<<std::endl; //Print out the number of events that only have a Muon and a Pion
   
   

   // ### Making a TCanvas ###
   TCanvas *c1= new TCanvas("c1","Pion Energy");
   c1->SetTicks();
   c1->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hPionEnergy->SetLineColor(kRed);
   hPionEnergy->SetLineStyle(0);
   hPionEnergy->SetLineWidth(3);
   hPionEnergy->SetMarkerStyle(8);
   hPionEnergy->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hPionEnergy->GetXaxis()->SetTitle("Pion Energy (MeV)");
   hPionEnergy->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hPionEnergy->GetYaxis()->SetTitle("Events / 10 MeV");
   hPionEnergy->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hPionEnergy->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t1 = new TLatex();
   t1->SetNDC();
   t1->SetTextFont(62);
   t1->SetTextSize(0.04);
   t1->SetTextAlign(40);
   t1->DrawLatex(0.1,0.90,"SciBooNE MC");
   t1->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg1 = new TLegend();
   leg1 = new TLegend(0.58,0.65,0.88,0.88);
   leg1->SetTextSize(0.04);
   leg1->SetTextAlign(12);
   leg1->SetFillColor(kWhite);
   leg1->SetLineColor(kWhite);
   leg1->SetShadowColor(kWhite);
   //leg1->SetHeader("#pi^{-} MC");
   leg1->AddEntry(hPionEnergy, "Pion Energy");
   leg1->Draw();



   // ### Making a TCanvas ###
   TCanvas *c2= new TCanvas("c2","Pion Momentum X");
   c2->SetTicks();
   c2->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hPionMomentumx->SetLineColor(kRed);
   hPionMomentumx->SetLineStyle(0);
   hPionMomentumx->SetLineWidth(3);
   hPionMomentumx->SetMarkerStyle(8);
   hPionMomentumx->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hPionMomentumx->GetXaxis()->SetTitle("Pion Momentum X (MeV/c^2)");
   hPionMomentumx->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hPionMomentumx->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hPionMomentumx->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hPionMomentumx->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t2 = new TLatex();
   t2->SetNDC();
   t2->SetTextFont(62);
   t2->SetTextSize(0.04);
   t2->SetTextAlign(40);
   t2->DrawLatex(0.1,0.90,"SciBooNE MC");
   t2->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg2 = new TLegend();
   leg2 = new TLegend(0.58,0.65,0.88,0.88);
   leg2->SetTextSize(0.04);
   leg2->SetTextAlign(12);
   leg2->SetFillColor(kWhite);
   leg2->SetLineColor(kWhite);
   leg2->SetShadowColor(kWhite);
   //leg2->SetHeader("#pi^{-} MC");
   leg2->AddEntry(hPionMomentumx, "Pion Momentum X");
   leg2->Draw();



   // ### Making a TCanvas ###
   TCanvas *c3= new TCanvas("c3","Pion Momentum Y");
   c3->SetTicks();
   c3->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hPionMomentumy->SetLineColor(kRed);
   hPionMomentumy->SetLineStyle(0);
   hPionMomentumy->SetLineWidth(3);
   hPionMomentumy->SetMarkerStyle(8);
   hPionMomentumy->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hPionMomentumy->GetXaxis()->SetTitle("Pion Momentum Y (MeV/c^2)");
   hPionMomentumy->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hPionMomentumy->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hPionMomentumy->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hPionMomentumy->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t3 = new TLatex();
   t3->SetNDC();
   t3->SetTextFont(62);
   t3->SetTextSize(0.04);
   t3->SetTextAlign(40);
   t3->DrawLatex(0.1,0.90,"SciBooNE MC");
   t3->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg3 = new TLegend();
   leg3 = new TLegend(0.58,0.65,0.88,0.88);
   leg3->SetTextSize(0.04);
   leg3->SetTextAlign(12);
   leg3->SetFillColor(kWhite);
   leg3->SetLineColor(kWhite);
   leg3->SetShadowColor(kWhite);
   //leg3->SetHeader("#pi^{-} MC");
   leg3->AddEntry(hPionMomentumy, "Pion Momentum Y");
   leg3->Draw();



   // ### Making a TCanvas ###
   TCanvas *c4= new TCanvas("c4","Pion Momentum Z");
   c4->SetTicks();
   c4->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hPionMomentumz->SetLineColor(kRed);
   hPionMomentumz->SetLineStyle(0);
   hPionMomentumz->SetLineWidth(3);
   hPionMomentumz->SetMarkerStyle(8);
   hPionMomentumz->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hPionMomentumz->GetXaxis()->SetTitle("Pion Momentum Z (MeV/c^2)");
   hPionMomentumz->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hPionMomentumz->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hPionMomentumz->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hPionMomentumz->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t4 = new TLatex();
   t4->SetNDC();
   t4->SetTextFont(62);
   t4->SetTextSize(0.04);
   t4->SetTextAlign(40);
   t4->DrawLatex(0.1,0.90,"SciBooNE MC");
   t4->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg4 = new TLegend();
   leg4 = new TLegend(0.58,0.65,0.88,0.88);
   leg4->SetTextSize(0.04);
   leg4->SetTextAlign(12);
   leg4->SetFillColor(kWhite);
   leg4->SetLineColor(kWhite);
   leg4->SetShadowColor(kWhite);
   //leg4->SetHeader("#pi^{-} MC");
   leg4->AddEntry(hPionMomentumz, "Pion Momentum Z");
   leg4->Draw();




   // ### Making a TCanvas ###
   TCanvas *c5= new TCanvas("c5","Muon Energy");
   c5->SetTicks();
   c5->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hMuonEnergy->SetLineColor(kRed);
   hMuonEnergy->SetLineStyle(0);
   hMuonEnergy->SetLineWidth(3);
   hMuonEnergy->SetMarkerStyle(8);
   hMuonEnergy->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hMuonEnergy->GetXaxis()->SetTitle("Muon Energy (MeV)");
   hMuonEnergy->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hMuonEnergy->GetYaxis()->SetTitle("Events / 10 MeV");
   hMuonEnergy->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hMuonEnergy->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t5 = new TLatex();
   t5->SetNDC();
   t5->SetTextFont(62);
   t5->SetTextSize(0.04);
   t5->SetTextAlign(40);
   t5->DrawLatex(0.1,0.90,"SciBooNE MC");
   t5->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg5 = new TLegend();
   leg5 = new TLegend(0.58,0.65,0.88,0.88);
   leg5->SetTextSize(0.04);
   leg5->SetTextAlign(12);
   leg5->SetFillColor(kWhite);
   leg5->SetLineColor(kWhite);
   leg5->SetShadowColor(kWhite);
   //leg5->SetHeader("#pi^{-} MC");
   leg5->AddEntry(hMuonEnergy, "Muon Energy");
   leg5->Draw();




   // ### Making a TCanvas ###
   TCanvas *c6= new TCanvas("c6","Muon Momentum X");
   c6->SetTicks();
   c6->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hMuonMomentumx->SetLineColor(kRed);
   hMuonMomentumx->SetLineStyle(0);
   hMuonMomentumx->SetLineWidth(3);
   hMuonMomentumx->SetMarkerStyle(8);
   hMuonMomentumx->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hMuonMomentumx->GetXaxis()->SetTitle("Muon Momentum X (MeV/c^2)");
   hMuonMomentumx->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hMuonMomentumx->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hMuonMomentumx->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hMuonMomentumx->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t6 = new TLatex();
   t6->SetNDC();
   t6->SetTextFont(62);
   t6->SetTextSize(0.04);
   t6->SetTextAlign(40);
   t6->DrawLatex(0.1,0.90,"SciBooNE MC");
   t6->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg6 = new TLegend();
   leg6 = new TLegend(0.58,0.65,0.88,0.88);
   leg6->SetTextSize(0.04);
   leg6->SetTextAlign(12);
   leg6->SetFillColor(kWhite);
   leg6->SetLineColor(kWhite);
   leg6->SetShadowColor(kWhite);
   //leg6->SetHeader("#pi^{-} MC");
   leg6->AddEntry(hMuonMomentumx, "Muon Momentum X");
   leg6->Draw();




   // ### Making a TCanvas ###
   TCanvas *c7= new TCanvas("c7","Muon Momentum Y");
   c7->SetTicks();
   c7->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hMuonMomentumy->SetLineColor(kRed);
   hMuonMomentumy->SetLineStyle(0);
   hMuonMomentumy->SetLineWidth(3);
   hMuonMomentumy->SetMarkerStyle(8);
   hMuonMomentumy->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hMuonMomentumy->GetXaxis()->SetTitle("Muon Momentum Y (MeV/c^2)");
   hMuonMomentumy->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hMuonMomentumy->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hMuonMomentumy->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hMuonMomentumy->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t7 = new TLatex();
   t7->SetNDC();
   t7->SetTextFont(62);
   t7->SetTextSize(0.04);
   t7->SetTextAlign(40);
   t7->DrawLatex(0.1,0.90,"SciBooNE MC");
   t7->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg7 = new TLegend();
   leg7 = new TLegend(0.58,0.65,0.88,0.88);
   leg7->SetTextSize(0.04);
   leg7->SetTextAlign(12);
   leg7->SetFillColor(kWhite);
   leg7->SetLineColor(kWhite);
   leg7->SetShadowColor(kWhite);
   //leg7->SetHeader("#pi^{-} MC");
   leg7->AddEntry(hMuonMomentumy, "Muon Momentum Y");
   leg7->Draw();





   // ### Making a TCanvas ###
   TCanvas *c8= new TCanvas("c8","Muon Momentum Z");
   c8->SetTicks();
   c8->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hMuonMomentumz->SetLineColor(kRed);
   hMuonMomentumz->SetLineStyle(0);
   hMuonMomentumz->SetLineWidth(3);
   hMuonMomentumz->SetMarkerStyle(8);
   hMuonMomentumz->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hMuonMomentumz->GetXaxis()->SetTitle("Muon Momentum Z (MeV/c^2)");
   hMuonMomentumz->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hMuonMomentumz->GetYaxis()->SetTitle("Events / 10 MeV/c^2");
   hMuonMomentumz->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hMuonMomentumz->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t8 = new TLatex();
   t8->SetNDC();
   t8->SetTextFont(62);
   t8->SetTextSize(0.04);
   t8->SetTextAlign(40);
   t8->DrawLatex(0.1,0.90,"SciBooNE MC");
   t8->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg8 = new TLegend();
   leg8 = new TLegend(0.58,0.65,0.88,0.88);
   leg8->SetTextSize(0.04);
   leg8->SetTextAlign(12);
   leg8->SetFillColor(kWhite);
   leg8->SetLineColor(kWhite);
   leg8->SetShadowColor(kWhite);
   //leg8->SetHeader("#pi^{-} MC");
   leg8->AddEntry(hMuonMomentumz, "Muon Momentum Z");
   leg8->Draw();
   
   // ### Making a TCanvas ###
   TCanvas *c12= new TCanvas("c12","Opening Angles");
   c12->SetTicks();
   c12->SetFillColor(kWhite);

   // === Histogram Drawing Settings ===
   hAngles->SetLineColor(kRed);
   hAngles->SetLineStyle(0);
   hAngles->SetLineWidth(3);
   hAngles->SetMarkerStyle(8);
   hAngles->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hAngles->GetXaxis()->SetTitle("Opening Angles");
   hAngles->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hAngles->GetYaxis()->SetTitle("Events");
   hAngles->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hAngles->Draw();

   // ############################
   // # Setting the Latex Header #
   // ############################
   TLatex *t12 = new TLatex();
   t12->SetNDC();
   t12->SetTextFont(62);
   t12->SetTextSize(0.04);
   t12->SetTextAlign(40);
   t12->DrawLatex(0.1,0.90,"SciBooNE MC");
   t12->DrawLatex(0.13,0.84,"");

   // ######################
   // # Setting the Legend #
   // ######################
   TLegend *leg12 = new TLegend();
   leg12 = new TLegend(0.58,0.65,0.88,0.88);
   leg12->SetTextSize(0.04);
   leg12->SetTextAlign(12);
   leg12->SetFillColor(kWhite);
   leg12->SetLineColor(kWhite);
   leg12->SetShadowColor(kWhite);
   leg12->AddEntry(hAngles, "Opening Angles");
   leg12->Draw();


   // ###############################
   // # Making Vertex Distributions #
   // ###############################
   TCanvas *c9= new TCanvas("c9","X Vertex Distribution");
   c9->SetTicks();
   c9->SetFillColor(kWhite);
   h1->Draw();

   TCanvas *c10= new TCanvas("c10","Y Vertex Distribution");
   c10->SetTicks();
   c10->SetFillColor(kWhite);
   h2->Draw();

   TCanvas *c11= new TCanvas("c11","Z Vertex Distribution");
   c11->SetTicks();
   c11->SetFillColor(kWhite);
   h3->Draw();

}//<---End void loop
