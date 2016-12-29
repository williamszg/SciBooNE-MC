#define NeutrinoModeBar_cxx
#include "NeutrinoModeBar.h"
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

TH1D *hAngles1 = new TH1D("hAngles1", "Opening Angles", 500, 0, 360); //This is the histogram for the opening angles between the muon and the pion


TH1D *h1 = new TH1D("h1", "X Vertex Distribution", 117, -0.25, 3.25);
TH1D *h2 = new TH1D("h2", "Y Vertex Distribution", 117, -0.25, 3.25);
TH1D *h3 = new TH1D("h3", "Z Vertex Distribution", 116, -0.25, 1.95);

TH2D *hMuonxy1 = new TH2D("hMuonxy1", "xy1", 100, 0, 3.0, 100, 0, 3.0); //At end of the SciBar Detector
TH2D *hMuonxz1 = new TH2D("hMuonxz1", "xz1", 100, 0, 3.0, 100, 1.5, 1.9); //At end of the SciBar Detector
TH2D *hMuonyz1 = new TH2D("hMuonyz1", "yz1", 100, 0, 3.0, 100, 1.5, 1.9); //At end of the SciBar Detector

TH2D *hMuonxy2 = new TH2D("hMuonxy2", "xy2", 100, 0, 3.0, 100, 0.2, 2.8); //At beginning of the MRD Detector
TH2D *hMuonxz2 = new TH2D("hMuonxz2", "xz2", 100, 0, 3.0, 100, 2.05, 2.45); //At beginning of the MRD Detector
TH2D *hMuonyz2 = new TH2D("hMuonyz2", "yz2", 100, 0.1, 2.9, 100, 2.05, 2.45); //At beginning of the MRD Detector




//##############################################
//### These are histograms for CC-Coh Events ###
//##############################################
TH1D *h4 = new TH1D("h4", "Layer Distribution", 26, 0, 26); //This is the histogram for which layer the muon stopped in in the steel layers

TH1D *h5 = new TH1D("h5", "Total CC-Coh Muon Momentum", 40, 0, 2000); //This is the histogram for the total number of CC events of the muon momentum
TH1D *h6 = new TH1D("h6", "Good CC-Coh Muon Momentum Stopped", 40, 0, 2000); //This is the histogram for the CC events that passed our cuts of the muon momentum
TH1D *h7 = new TH1D("h7", "Total CC-Coh Muon Angle", 40, 0, 180); //This is the histogram for the total number of CC events of the muon angle
TH1D *h8 = new TH1D("h8", "Good CC-Coh Muon Angle Stopped", 40, 0, 180); //This is the histogram for the CC events that passed our cuts of the muon angle

TH1D *h9 = new TH1D("h9", "Good CC-Coh Muon Momentum Non-Stopped", 40, 0, 2000); //This is the histogram for the good number of CC events of the muon momentum that did not stop within the muon detector
TH1D *h10 = new TH1D("h10", "Good CC-Coh Muon Angle Non-Stopped", 40, 0, 180); //This is the histogram for the good number of CC events of the muon angle that did not stop within the muon detector

TH1D *h11 = new TH1D("h11", "Total Good CC-Coh Events for Muon Momentum", 40, 0, 2000); //This is the stopped and nonstopped good sample of CC events for muon momentum
TH1D *h12 = new TH1D("h12", "Total Good CC-Coh Events for Muon Angle", 40, 0, 180); //This is the stopped and nonstopped good sample of CC events for muon angle




//##########################################
//### These are histograms for CC Events ###
//##########################################
TH1D *h13 = new TH1D("h13", "Total CC Events for Muon Momentum", 40, 0, 2000); //This is the histogram for Total CC Events for the muon momentum
TH1D *h14 = new TH1D("h14", "Total CC Events for Muon Angle", 40, 0, 180); //This is the histogram for Total CC Events for the muon angle

TH1D *h15 = new TH1D("h15", "Good CC Events for Muon Momentum Stopped", 40, 0, 2000); //This is the histogram for Good CC Events that were stopped for muon momentum
TH1D *h16 = new TH1D("h16", "Good CC Events for Muon Angle Stopped", 40, 0, 180); //This is the histogram for Good CC Events that were stopped for muon angle

TH1D *h17 = new TH1D("h17", "Good CC Events for Muon Momentum Non-Stopped", 40, 0, 2000); //This is the histogram for Good CC Events that were non-stopped for muon momentum
TH1D *h18 = new TH1D("h18", "Good CC Events for Muon Angle Non-Stopped", 40, 0, 180); //This is the histogram for Good CC Events that were non-stopped for muon angle

TH1D *h19 = new TH1D("h19", "Total Good CC Events for Muon Momentum ", 40, 0, 2000); //This is the histogram for Good CC Events that were good both non-stopped and stopped of muon momentum
TH1D *h20 = new TH1D("h20", "Total Good CC Events for Muon Angle", 40, 0, 180); //This is the histogram for Good CC Events that were good both non-stopped and stopped of muon angle




void NeutrinoModeBar::Loop()
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
   double rm1 = 0;
   double rp1 = 0;
   double cA = 0;
   int stopped = 0;
   int nstopped = 0;
   int gevents = 0;
   int r = 0;
   int nCCevents = 0;
   int nCCGevents = 0;
   int nCCstoppedevents = 0;
   int nCCnonstoppedevents = 0;


   for (Long64_t jentry=0; jentry<nentries;jentry++) 
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      TRandom3 *rand = new TRandom3();
      TRandom3 *flat = new TRandom3();
      rand->SetSeed(jentry);
      flat->SetSeed(jentry);
      double Xpos = rand->Gaus(1.5,1.3);
      while (Xpos<0 || Xpos>3.0) { Xpos = rand->Gaus(1.5,1.3); }
      double Ypos = rand->Gaus(1.5,1.05);
      while (Ypos<0 || Ypos>3.0) { Ypos = rand->Gaus(1.5,1.05); }
      double Zpos = flat->Uniform(0,1.7);
      h1->Fill(Xpos);
      h2->Fill(Ypos);
      h3->Fill(Zpos);
      double mangle = 0; //This is the angle of the muon in the xy and z plane (theta)

      for (int npart = 0; npart < StdHepN; npart++)
      {

      if ((StdHepPdg[npart] == 13 || StdHepPdg[npart] == -13) && StdHepStatus[npart] == 1)
         {

         mpresent = 1;
         nmpresent++;
         nmpart = npart;         

         } //<---End counting of muon in single event
      if ((StdHepPdg[npart] == 211 || StdHepPdg[npart] == -211) && mpresent == 1 && StdHepStatus[npart] == 1)

         {

         nMPevents++;
         mpresent = 0;
         nppresent++;
         nppart = npart;

         } //<---End checking for both a muon and a pion in an event

      if (StdHepStatus[npart] == 1)

         {

         tfstate++;

         } //<---End checking for the total number of final state particles coming from the interaction




      //#######################################################
      //### This is the If statement to check for CC Events ###
      //#######################################################
      if (nmpresent >= 1) //Is the total number of muons in the event at least one?
         {

         if (nppresent >= 1) //Is the total number of pions in the event at least one?
            {

            if ((npart == StdHepN - 1) && StdHepP4[nmpart][2]>0 && StdHepP4[nppart][2]>0) //Are you done slewing over all of the particles in this event?
               {
               
               nCCevents++; //Count the number of CC Events that occurred

               double angle1 = (180/PI)*acos (((StdHepP4[nppart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nppart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nppart][2]*StdHepP4[nmpart][2])) / sqrt ((((StdHepP4[nppart][0]*StdHepP4[nppart][0]) + (StdHepP4[nppart][1]*StdHepP4[nppart][1]) + (StdHepP4[nppart][2]*StdHepP4[nppart][2]))*((StdHepP4[nmpart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nmpart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nmpart][2]*StdHepP4[nmpart][2]))))); //This is the first attempt to find the angle between the momentum vectors of the muon and the pion using the brute force dot product by definition

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
               double angle2 = (180/PI)*acos( dot1/(mag1*mag2) ); //This is the second way of finding the angle between the muon and pion momentums

               cA = z2/mag1; //This is the cosine of the muon angle
               mangle = (180/PI)*acos(cA); //This is the theta angle of the muon in degrees

               h13->Fill(mag1*1000); //Fill the h13 histogram in MeV for Total CC Events muon momentum
               h14->Fill(mangle); //Fill the h14 histogram with the angle for Total CC Events muon angle

               double b1 = (1.7 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution for the muon
               double b2 = (1.7 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution for the pion
               double m1 = Xpos + StdHepP4[nmpart][0]*b1; //This is the evolution of the x position of the muon
               double p1 = Xpos + StdHepP4[nppart][0]*b2; //This is the evolution of the x position of the pion
               double m2 = Ypos + StdHepP4[nmpart][1]*b1; //This is the evolution of the y position of the muon
               double p2 = Ypos + StdHepP4[nppart][1]*b2; //This is the evolution of the y position of the pion
               double b3 = (1.7 + 0.55 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution of the muon to the beginning of the MRD
               double b4 = (1.7 + 0.55 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution of the pion to the beginning of the  MRD
               double m12 = Xpos + StdHepP4[nmpart][0]*b3; //This is the evolution of the x position of the muon to the beginning of the MRD
               double p12 = Xpos + StdHepP4[nppart][0]*b4; //This is the evolution of the x position of the pion to the beginning of the MRD
               double m22 = Ypos + StdHepP4[nmpart][1]*b3; //This is the evolution of the y position of the muon to the beginning of the MRD
               double p22 = Ypos + StdHepP4[nppart][1]*b4; //This is the evolution of the y position of the pion to the beginning of the MRD
               double b5 = (1.7 + 0.55 + 1.375 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution of the muon through the MRD
               double b6 = (1.7 + 0.55 + 1.375 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution of the pion through the MRD
               double m13 = Xpos + StdHepP4[nmpart][0]*b5; //This is the evolution of the x position of the muon through the MRD
               double p13 = Xpos + StdHepP4[nppart][0]*b6; //This is the evolution of the x position of the pion through the MRD
               double m23 = Ypos + StdHepP4[nmpart][1]*b5; //This is the evolution of the y position of the muon through the MRD
               double p23 = Ypos + StdHepP4[nppart][1]*b6; //This is the evolution of the y position of the pion through the MRD
               double b7 = (.006/StdHepP4[nmpart][2])*StdHepP4[nmpart][0]; //This is the distance traveled through a scintillator layer added to the x direction
               double b8 = (.006/StdHepP4[nmpart][2])*StdHepP4[nmpart][1]; //This is the distance traveled through a scintillator layer added to the y direction
               double b9 = (.0508/StdHepP4[nmpart][2])*StdHepP4[nmpart][0]; //This is the distance traveled through a steel layer added to the x direction
               double b10 = (.0508/StdHepP4[nmpart][2])*StdHepP4[nmpart][1]; //This is the distance traveled through a steel layer added to the y direction
               double rm1 = 100*sqrt(((1.7 - Zpos)*(1.7 - Zpos)) + ((m1 - Xpos)*(m1 - Xpos)) + ((m2 - Ypos)*(m2 - Ypos))); //This is the length that the muon traveled from beginning to end of SciBar Detector
               double rp1 = 100*sqrt(((1.7 - Zpos)*(1.7 - Zpos)) + ((p1 - Xpos)*(p1 - Xpos)) + ((p2 - Ypos)*(p2 - Ypos))); //This is the length that the muon traveled from beginning to end of SciBar Detector
               double dE1 = 2.04*rm1; //This is the energy lost in MeV by the muon traveling through the SciBar Detector
               double dE2 = 2.04*rp1; //This is the energy lost in MeV by the pion traveling through the SciBar Detector
               double E1 = StdHepP4[nmpart][3]*1000 - dE1; //This is the change in energy of the muon up to the end of the SciBar Detector

               if (m2>0.2 && m2<2.8 && m1>0 && m1<3.0 && m12>0 && m12<3.0 && m22>0.2 && m22<2.8 && E1>=0)
                  {

                  double Emf1 = E1; //Defining the muon final energy variable
                  double dE3 = 0; //Defining the variable to be used for the scintillator change calculations
                  double dE4 = 0; //Defining the variable to be used for the steel change calculations
                  int layer = 0; //Defining the layer of scintillation the muon went to
                  int n = 0; //Defining the layer of steel the muon went to
                  double rm3 = 0;
                  double rm4 = 0;
                  double m14 = 0;
                  double m24 = 0;
                  double m15 = m12;
                  double m25 = m22;

                  while (Emf1>0)
                     {

                     layer++;
                     m15 = m12 + layer*b7 + n*b9; //This is increasing the muon x position for a scintillator layer
                     m25 = m22 + layer*b8 + n*b10; //This is increasing the muon y position for a scintillator layer
                     rm3 = 100*sqrt((.006)*(.006) + (b7)*(b7) + (b8)*(b8)); //Path length the muon traveled through scintillator
                     dE3 = 2.04*rm3; //This is the amount the energy will change from traveling through the scintillator layer
                     Emf1 = Emf1 - dE3; //Losing energy due to scintillator

                     if (Emf1>0)
                        {

                        n++;
                        m14 = m15 + b9; //This is increasing the muon x position for a steel layer
                        m24 = m25 + b10; //This is increasing the muon y position for a steel layer
                        rm4 = 100*sqrt((.0508)*(.0508) + (b9)*(b9) + (b10)*(b10)); //Path length the muon traveled through steel
                        dE4 = 11.43*rm4; //This is the amount the energy will change from traveling through the steel layer
                        Emf1 = Emf1 - dE4; //Losing energy due to steel

                        } //<---End if statement within the while loop

                     } //<---End while statement

                  if (Emf1<=0)
                     {

                     h19->Fill(mag1*1000); //Fill the total good CC histogram with the muon momentum in MeV
                     h20->Fill(mangle); //Fill the total good CC histogram with the muon angle

                     nCCGevents++; //Increases the number counted for the total good events classification

                     } 

                  if (Emf1<=0 && layer<=25 && n<25 && m15>=0 && m25>=0.2 && m15<=3 && m25<=2.8 && m14>0 && m14<3 && m24<2.8 && m24>0.2)
                     {

                     h15->Fill(mag1*1000); //Fill the h15 histogram with the good CC stopped muon momentum
                     h16->Fill(mangle); //Fill the h16 histogram with the good CC stopped muon angle

                     nCCstoppedevents++; //Count the number of CC Stopped Events

                     } else {

                            if (Emf1<=0) {

                                         h17->Fill(mag1*1000); //Fill the CC nonstopped histogram with the muon momentum in MeV
                                         h18->Fill(mangle); //Fill the CC nonstopped histogram with the muon angle
                                         nCCnonstoppedevents++; //Count the number of CC Not-Stopped Events

                                         }

                            }
                     
                     layer = 0; //Reset the layer counter

                     } //<---End if statement that checks if the event was a good event


               }

            }

         } //<---End if statement for CC Events.




      //################################################################
      //### This is the If statement to check for CC-Coh Pion Events ###
      //################################################################
      if (nmpresent == 1) //Is the total number of muons in the event one?
         {
         
         if (nppresent == 1) //Is the total number of pions in the event one?
            {

            if ((npart == StdHepN - 1) && tfstate == 2 && StdHepP4[nmpart][2]>0 && StdHepP4[nppart][2]>0) //Are there only two particles in the final state in this interaction? And are you done slewing over all of the particles in this event?
               {
               
               double angle1 = (180/PI)*acos (((StdHepP4[nppart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nppart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nppart][2]*StdHepP4[nmpart][2])) / sqrt ((((StdHepP4[nppart][0]*StdHepP4[nppart][0]) + (StdHepP4[nppart][1]*StdHepP4[nppart][1]) + (StdHepP4[nppart][2]*StdHepP4[nppart][2]))*((StdHepP4[nmpart][0]*StdHepP4[nmpart][0]) + (StdHepP4[nmpart][1]*StdHepP4[nmpart][1]) + (StdHepP4[nmpart][2]*StdHepP4[nmpart][2]))))); //This is the first attempt to find the angle between the momentum vectors of the muon and the pion using the brute force dot product by definition

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
               double angle2 = (180/PI)*acos( dot1/(mag1*mag2) ); //This is the second way of finding the angle between the muon and pion momentums
               
               cA = z2/mag1; //This is the cosine of the muon angle
               mangle = (180/PI)*acos(cA); //This is the theta angle of the muon in degrees

               h5->Fill(mag1*1000); //Fill the h5 histogram in MeV
               h7->Fill(mangle); //Fill the h7 histogram with the angle

               nMAPevents++; //Count the number of muon and pion as the only end products events

               double b1 = (1.7 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution for the muon
               double b2 = (1.7 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution for the pion
               double m1 = Xpos + StdHepP4[nmpart][0]*b1; //This is the evolution of the x position of the muon
               double p1 = Xpos + StdHepP4[nppart][0]*b2; //This is the evolution of the x position of the pion
               double m2 = Ypos + StdHepP4[nmpart][1]*b1; //This is the evolution of the y position of the muon
               double p2 = Ypos + StdHepP4[nppart][1]*b2; //This is the evolution of the y position of the pion
               double b3 = (1.7 + 0.55 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution of the muon to the beginning of the MRD
               double b4 = (1.7 + 0.55 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution of the pion to the beginning of the  MRD
               double m12 = Xpos + StdHepP4[nmpart][0]*b3; //This is the evolution of the x position of the muon to the beginning of the MRD
               double p12 = Xpos + StdHepP4[nppart][0]*b4; //This is the evolution of the x position of the pion to the beginning of the MRD
               double m22 = Ypos + StdHepP4[nmpart][1]*b3; //This is the evolution of the y position of the muon to the beginning of the MRD
               double p22 = Ypos + StdHepP4[nppart][1]*b4; //This is the evolution of the y position of the pion to the beginning of the MRD
               double b5 = (1.7 + 0.55 + 1.375 - Zpos)/StdHepP4[nmpart][2]; //This is the time for the evolution of the muon through the MRD
               double b6 = (1.7 + 0.55 + 1.375 - Zpos)/StdHepP4[nppart][2]; //This is the time for the evolution of the pion through the MRD
               double m13 = Xpos + StdHepP4[nmpart][0]*b5; //This is the evolution of the x position of the muon through the MRD
               double p13 = Xpos + StdHepP4[nppart][0]*b6; //This is the evolution of the x position of the pion through the MRD
               double m23 = Ypos + StdHepP4[nmpart][1]*b5; //This is the evolution of the y position of the muon through the MRD
               double p23 = Ypos + StdHepP4[nppart][1]*b6; //This is the evolution of the y position of the pion through the MRD
               double b7 = (.006/StdHepP4[nmpart][2])*StdHepP4[nmpart][0]; //This is the distance traveled through a scintillator layer added to the x direction
               double b8 = (.006/StdHepP4[nmpart][2])*StdHepP4[nmpart][1]; //This is the distance traveled through a scintillator layer added to the y direction
               double b9 = (.0508/StdHepP4[nmpart][2])*StdHepP4[nmpart][0]; //This is the distance traveled through a steel layer added to the x direction
               double b10 = (.0508/StdHepP4[nmpart][2])*StdHepP4[nmpart][1]; //This is the distance traveled through a steel layer added to the y direction
               double rm1 = 100*sqrt(((1.7 - Zpos)*(1.7 - Zpos)) + ((m1 - Xpos)*(m1 - Xpos)) + ((m2 - Ypos)*(m2 - Ypos))); //This is the length that the muon traveled from beginning to end of SciBar Detector
               double rp1 = 100*sqrt(((1.7 - Zpos)*(1.7 - Zpos)) + ((p1 - Xpos)*(p1 - Xpos)) + ((p2 - Ypos)*(p2 - Ypos))); //This is the length that the muon traveled from beginning to end of SciBar Detector
               double dE1 = 2.04*rm1; //This is the energy lost in MeV by the muon traveling through the SciBar Detector
               double dE2 = 2.04*rp1; //This is the energy lost in MeV by the pion traveling through the SciBar Detector
               double E1 = StdHepP4[nmpart][3]*1000 - dE1; //This is the change in energy of the muon up to the end of the SciBar Detector

               if (m2>0.2 && m2<2.8 && m1>0 && m1<3.0 && m12>0 && m12<3.0 && m22>0.2 && m22<2.8 && E1>=0)
                  {

                  double Emf1 = E1; //Defining the muon final energy variable
                  double dE3 = 0; //Defining the variable to be used for the scintillator change calculations
                  double dE4 = 0; //Defining the variable to be used for the steel change calculations
                  int layer = 0; //Defining the layer of scintillation the muon went to
                  int n = 0; //Defining the layer of steel the muon went to
                  double rm3 = 0;
                  double rm4 = 0;
                  double m14 = 0;
                  double m24 = 0;
                  double m15 = m12;
                  double m25 = m22;

                  while (Emf1>0) 
                     {

                     layer++;
                     m15 = m12 + layer*b7 + n*b9; //This is increasing the muon x position for a scintillator layer
                     m25 = m22 + layer*b8 + n*b10; //This is increasing the muon y position for a scintillator layer
                     rm3 = 100*sqrt((.006)*(.006) + (b7)*(b7) + (b8)*(b8)); //Path length the muon traveled through scintillator
                     dE3 = 2.04*rm3; //This is the amount the energy will change from traveling through the scintillator layer
                     Emf1 = Emf1 - dE3; //Losing energy due to scintillator

                     if (Emf1>0)
                        {
                        
                        n++;
                        m14 = m15 + b9; //This is increasing the muon x position for a steel layer
                        m24 = m25 + b10; //This is increasing the muon y position for a steel layer
                        rm4 = 100*sqrt((.0508)*(.0508) + (b9)*(b9) + (b10)*(b10)); //Path length the muon traveled through steel
                        dE4 = 11.43*rm4; //This is the amount the energy will change from traveling through the steel layer
                        Emf1 = Emf1 - dE4; //Losing energy due to steel

                        } //<---End if statement within the while loop

                     } //<---End while statement

                  if (Emf1<=0)
                     {

                     h11->Fill(mag1*1000); //Fill the total good histogram with the muon momentum in MeV
                     h12->Fill(mangle); //Fill the total good histogram with the muon angle
                     gevents++; //Increases the number counted for the total good events classification

                     }

                  if (Emf1<=0 && layer<=25 && n<25 && m15>=0 && m25>=0.2 && m15<=3 && m25<=2.8 && m14>0 && m14<3 && m24<2.8 && m24>0.2)
                     {

                     hPionMomentumx->Fill(StdHepP4[nppart][0] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hPionMomentumy->Fill(StdHepP4[nppart][1] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hPionMomentumz->Fill(StdHepP4[nppart][2] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hPionEnergy->Fill(StdHepP4[nppart][3] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV

                     hMuonMomentumx->Fill(StdHepP4[nmpart][0] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hMuonMomentumy->Fill(StdHepP4[nmpart][1] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hMuonMomentumz->Fill(StdHepP4[nmpart][2] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV
                     hMuonEnergy->Fill(StdHepP4[nmpart][3] * 1000); //Note: We multiply by 1000 to convert from GeV to MeV

                     hAngles1->Fill(angle1); //This fills the first Opening Angles histogram with the angle between the two momentums

                     hMuonxy1->Fill(m1, m2); //Fill the hMuonxy1 histogram end of SciBar Detector
                     hMuonxz1->Fill(m1, 1.7); //Fill the hMuonxz1 histogram end of SciBar Detector
                     hMuonyz1->Fill(m2, 1.7); //Fill the hMuonyz1 histogram end of SciBar Detector

                     hMuonxy2->Fill(m12, m22); //Fill the hMuonxy2 histogram beginning of MRD
                     hMuonxz2->Fill(m12, 2.25); //Fill the hMuonxz2 histogram beginning of MRD
                     hMuonyz2->Fill(m22, 2.25); //Fill the hMuonyz2 histogram beginning of MRD

                     h4->Fill(layer);
                  
                     h6->Fill(mag1*1000); //Fill the h6 histogram with the good CC muon momentum
                     h8->Fill(mangle); //Fill the h8 histogram with the good CC muon angle

                     nppresent = 0;
                     nmpresent = 0;
                     nmpart = 0;
                     nppart = 0;
                     tfstate = 0;
                     stopped++;

                     } else {

                            if (Emf1<=0) {

                                         h9->Fill(mag1*1000); //Fill the nonstopped histogram with the muon momentum in MeV
                                         h10->Fill(mangle); //Fill the nonstopped histogram with the muon angle
                                         nstopped++;

                                         }

                            }

                  } //<---End if statement that checks if the event was a good event


               }

            }

         } //<---End if statement for exclusive pion and muon presence.

      } //<---End npart for-loop

   mpresent = 0; //Reset a counter
   nmpresent = 0; //Reset a counter
   nppresent = 0; //Reset a counter
   tfstate = 0; //Reset a counter
   r = jentry + 1; //Counting the total number of events

   } //<---End jentry for-loop

   


   std::cout<<"Total Number of Simulated Events = "<<r<<std::endl; //Print out the total number of simulated events.
   std::cout<<"Number of Events Containing a Muon and a Pion = "<<nMPevents<<std::endl; //Print out the number of events containing a Muon and a Pion


   //##################################################
   //### Printing out information for CC-Coh Events ###
   //##################################################
   std::cout<<"Number of Events Containing a Muon and a Pion, exclusively = "<<nMAPevents<<std::endl; //Print out the number of events that only have a Muon and a Pion
   std::cout<<"Number of ''Good'' Events That Happen both Non-Stopped and Stopped = "<<gevents<<std::endl; //Print out the number of good events in total that occured. The good classification means it at least entered one layer of the MRD
   std::cout<<"Number of CC-Coh Events Completely Contained in MRD with our cuts = "<<stopped<<std::endl; //Print out the number of events that stopped within MRD
   std::cout<<"Number of CC-Coh Events Not Completely Contained in MRD with our cuts = "<<nstopped<<std::endl; //Print out the number of events that did not stop within the MRD


   //##############################################
   //### Printing out information for CC Events ###
   //##############################################
   std::cout<<"Number of CC Events That Happened both Non-Stopped and Stopped = "<<nCCevents<<std::endl; //Print out the number of CC events.
   std::cout<<"Number of ''Good'' Events That Happened both Non-Stopped and Stopped = "<<nCCGevents<<std::endl; //Print out the number of good events in total that occured. The good classification means it at least entered one layer of the MRD
   std::cout<<"Number of CC Events Completely Contained in MRD with our cuts = "<<nCCstoppedevents<<std::endl; //Print out the number of events that stopped within MRD
   std::cout<<"Number of CC Events Not Completely Contained in MRD with our cuts = "<<nCCnonstoppedevents<<std::endl; //Print out the number of events that did not stop within the MRD




   //########################################
   //### Preparing the histogram canvases ###
   //########################################
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
   hAngles1->SetLineColor(kRed);
   hAngles1->SetLineStyle(0);
   hAngles1->SetLineWidth(3);
   hAngles1->SetMarkerStyle(8);
   hAngles1->SetMarkerSize(0.9);

   // ### Labeling the X axis ###
   hAngles1->GetXaxis()->SetTitle("Opening Angles (Degrees)");
   hAngles1->GetXaxis()->CenterTitle();

   // ### Labeling the Y axis ###
   hAngles1->GetYaxis()->SetTitle("Events");
   hAngles1->GetYaxis()->CenterTitle();

   // ### Drawing ###
   hAngles1->Draw();

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
   leg12->AddEntry(hAngles1, "Opening Angles");
   leg12->Draw();




   // ###############################
   // # Making Vertex Distributions #
   // ###############################
   TCanvas *c9= new TCanvas("c9","X Vertex Distribution");
   c9->SetTicks();
   c9->SetFillColor(kWhite);
   h1->GetXaxis()->SetTitle("Length (meters)");
   h1->GetXaxis()->CenterTitle();
   h1->GetYaxis()->SetTitle("Events (#/.03m)");
   h1->GetYaxis()->CenterTitle();
   h1->Draw();

   TCanvas *c10= new TCanvas("c10","Y Vertex Distribution");
   c10->SetTicks();
   c10->SetFillColor(kWhite);
   h2->GetXaxis()->SetTitle("Length (meters)");
   h2->GetXaxis()->CenterTitle();
   h2->GetYaxis()->SetTitle("Events (#/.03m)");
   h2->GetYaxis()->CenterTitle();
   h2->Draw();

   TCanvas *c11= new TCanvas("c11","Z Vertex Distribution");
   c11->SetTicks();
   c11->SetFillColor(kWhite);
   h3->GetXaxis()->SetTitle("Length (meters)");
   h3->GetXaxis()->CenterTitle();
   h3->GetYaxis()->SetTitle("Events (#/.017m)");
   h3->GetYaxis()->CenterTitle();
   h3->Draw();

   // ##########################
   // # Detector Hits in Plane #
   // ##########################
   TCanvas *c13= new TCanvas("c13", "Muon XY at end of SciBar");
   c13->SetTicks();
   c13->SetFillColor(kWhite);
   hMuonxy1->Draw();

   TCanvas *c14= new TCanvas("c14", "Muon XZ at end of SciBar");
   c14->SetTicks();
   c14->SetFillColor(kWhite);
   hMuonxz1->Draw();

   TCanvas *c15= new TCanvas("c15", "Muon YZ at end of SciBar");
   c15->SetTicks();
   c15->SetFillColor(kWhite);
   hMuonyz1->Draw();

   TCanvas *c16= new TCanvas("c16", "Muon XY at Beginning of MRD");
   c16->SetTicks();
   c16->SetFillColor(kWhite);
   hMuonxy2->Draw();

   TCanvas *c17= new TCanvas("c17", "Muon XZ at Beginning of MRD");
   c17->SetTicks();
   c17->SetFillColor(kWhite);
   hMuonxz2->Draw();

   TCanvas *c18= new TCanvas("c18", "Muon YZ at Beginning of MRD");
   c18->SetTicks();
   c18->SetFillColor(kWhite);
   hMuonyz2->Draw();

   TCanvas *c19 = new TCanvas("c19", "Layer the Muon Stopped In");
   c19->SetTicks();
   c19->SetFillColor(kWhite);
   h4->Draw();

   TCanvas *c20 = new TCanvas("c20", "Total CC-Coh Muon Momentum");
   c20->SetTicks();
   c20->SetFillColor(kWhite);
   h5->SetLineColor(kBlack);
   h5->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h5->GetXaxis()->CenterTitle();
   h5->GetYaxis()->SetTitle("Events (#/50MeV)");
   h5->GetYaxis()->CenterTitle();
   h5->Draw();

   TCanvas *c21 = new TCanvas("c21", "Good CC-Coh Muon Momentum Stopped");
   c21->SetTicks();
   c21->SetFillColor(kWhite);
   h6->SetLineColor(kBlue);
   h6->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h6->GetXaxis()->CenterTitle();
   h6->GetYaxis()->SetTitle("Events (#/50MeV)");
   h6->GetYaxis()->CenterTitle();
   h6->Draw();

   TCanvas *c22 = new TCanvas("c22", "Total CC-Coh Muon Angle");
   c22->SetTicks();
   c22->SetFillColor(kWhite);
   h7->SetLineColor(kBlack);
   h7->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h7->GetXaxis()->CenterTitle();
   h7->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h7->GetYaxis()->CenterTitle();
   h7->Draw();

   TCanvas *c23 = new TCanvas("c23", "Good CC-Coh Muon Angle Stopped");
   c23->SetTicks();
   c23->SetFillColor(kWhite);
   h8->SetLineColor(kBlue);
   h8->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h8->GetXaxis()->CenterTitle();
   h8->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h8->GetYaxis()->CenterTitle();
   h8->Draw();

   TCanvas *c24 = new TCanvas("c24", "Total Non-Stopped CC-Coh Muon Momentum");
   c24->SetTicks();
   c24->SetFillColor(kWhite);
   h9->SetLineColor(kRed);
   h9->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h9->GetXaxis()->CenterTitle();
   h9->GetYaxis()->SetTitle("Events (#/50MeV)");
   h9->GetYaxis()->CenterTitle();
   h9->Draw();

   TCanvas *c25 = new TCanvas("c25", "Good Non-Stopped CC-Coh Muon Angle");
   c25->SetTicks();
   c25->SetFillColor(kWhite);
   h10->SetLineColor(kRed);
   h10->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h10->GetXaxis()->CenterTitle();
   h10->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h10->GetYaxis()->CenterTitle();
   h10->Draw();

   TCanvas *c26 = new TCanvas("c26", "Total Good CC-Coh Muon Momentum");
   c26->SetTicks();
   c26->SetFillColor(kWhite);
   h11->SetLineColor(kMagenta+3);
   h11->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h11->GetXaxis()->CenterTitle();
   h11->GetYaxis()->SetTitle("Events (#/50Mev)");
   h11->GetYaxis()->CenterTitle();
   h11->Draw();

   TCanvas *c27 = new TCanvas("c27", "Total Good CC-Coh Muon Angle");
   c27->SetTicks();
   c27->SetFillColor(kWhite);
   h12->SetLineColor(kMagenta+3);
   h12->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h12->GetXaxis()->CenterTitle();
   h12->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h12->GetYaxis()->CenterTitle();
   h12->Draw();

   TCanvas *c28 = new TCanvas("c28", "Total CC Muon Momentum");
   c28->SetTicks();
   c28->SetFillColor(kWhite);
   h13->SetLineColor(kMagenta+3);
   h13->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h13->GetXaxis()->CenterTitle();
   h13->GetYaxis()->SetTitle("Events (#/50MeV)");
   h13->GetYaxis()->CenterTitle();
   h13->Draw();

   TCanvas *c29 = new TCanvas("c29", "Total CC Muon Angle");
   c29->SetTicks();
   c29->SetFillColor(kWhite);
   h14->SetLineColor(kMagenta+3);
   h14->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h14->GetXaxis()->CenterTitle();
   h14->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h14->GetYaxis()->CenterTitle();
   h14->Draw();

   TCanvas *c30 = new TCanvas("c30", "Good Stopped CC Muon Momentum");
   c30->SetTicks();
   c30->SetFillColor(kWhite);
   h15->SetLineColor(kMagenta+3);
   h15->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h15->GetXaxis()->CenterTitle();
   h15->GetYaxis()->SetTitle("Events (#/50MeV)");
   h15->GetYaxis()->CenterTitle();
   h15->Draw();

   TCanvas *c31 = new TCanvas("c31", "Good Stopped CC Muon Angle");
   c31->SetTicks();
   c31->SetFillColor(kWhite);
   h16->SetLineColor(kMagenta+3);
   h16->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h16->GetXaxis()->CenterTitle();
   h16->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h16->GetYaxis()->CenterTitle();
   h16->Draw();

   TCanvas *c32 = new TCanvas("c32", "Good Non-Stopped CC Muon Momentum");
   c32->SetTicks();
   c32->SetFillColor(kWhite);
   h17->SetLineColor(kMagenta+3);
   h17->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h17->GetXaxis()->CenterTitle();
   h17->GetYaxis()->SetTitle("Events (#/50MeV)");
   h17->GetYaxis()->CenterTitle();
   h17->Draw();

   TCanvas *c33 = new TCanvas("c33", "Good Non-Stopped CC Muon Angle");
   c33->SetTicks();
   c33->SetFillColor(kWhite);
   h18->SetLineColor(kMagenta+3);
   h18->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h18->GetXaxis()->CenterTitle();
   h18->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h18->GetYaxis()->CenterTitle();
   h18->Draw();

   TCanvas *c34 = new TCanvas("c34", "Total Good CC Muon Momentum");
   c34->SetTicks();
   c34->SetFillColor(kWhite);
   h19->SetLineColor(kMagenta+3);
   h19->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
   h19->GetXaxis()->CenterTitle();
   h19->GetYaxis()->SetTitle("Events (#/50MeV)");
   h19->GetYaxis()->CenterTitle();
   h19->Draw();

   TCanvas *c35 = new TCanvas("c35", "Total Good CC Muon Angle");
   c35->SetTicks();
   c35->SetFillColor(kWhite);
   h20->SetLineColor(kMagenta+3);
   h20->GetXaxis()->SetTitle("Muon Angle (Degrees)");
   h20->GetXaxis()->CenterTitle();
   h20->GetYaxis()->SetTitle("Events (#/4.5Degrees)");
   h20->GetYaxis()->CenterTitle();
   h20->Draw();




   //#################################
   //# Saving the Data to Root Files #
   //#################################
   TFile *TMuonInfo = new TFile("./ROOTFILES/totalmuoninfoRSBar.root", "RECREATE");
   h5->Write("TMuonMom_1");
   h6->Write("GMuonMomS_1");
   h7->Write("TMuonCos_1");
   h8->Write("GMuonCosS_1");
   h9->Write("GMuonMomNS_1");
   h10->Write("GMuonCosNS_1");
   h11->Write("TGMuonMom_1");
   h12->Write("TGMuonCos_1");
   h13->Write("CCTMuonMom_1");
   h14->Write("CCTMuonCos_1");
   h15->Write("CCGMuonMomS_1");
   h16->Write("CCGMuonCosS_1");
   h17->Write("CCGMuonMomNS_1");
   h18->Write("CCGMuonCosNS_1");
   h19->Write("CCTGMuonMom_1");
   h20->Write("CCTGMuonCos_1");
   TMuonInfo->Write();
   TMuonInfo->Close();


}//<---End void loop
