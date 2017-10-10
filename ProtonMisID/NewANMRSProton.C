#define NewANMRSProton_cxx
#include "NewANMRSProton.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

//-----------------------------|
//---       Histograms      ---|
//-----------------------------|
TH1D *hTotalProtonEnergy = new TH1D("hTotalProtonEnergy", "The Energies of all of the Proton Events", 50, 0, 2500);
TH1D *hTotalProtonMomentum = new TH1D("hTotalProtonMomentum", "The Momentums of all of the Proton Events", 50, 0, 2500);
TH1D *hTotalProtonAngle = new TH1D("hTotalProtonAngle", "The Angles of all of the Proton Events", 60, 0, 180);

TH1D *hProtonEnergyAfterSciBar = new TH1D("hProtonEnergyAfterSciBar", "The Energies of the Protons After Traversing SciBar", 50, 0, 2500);
TH1D *hProtonAngleAfterSciBar = new TH1D("hProtonAngleAfterSciBar", "The Angles of the Protons After Traversing SciBar", 60, 0, 180);

TH1D *hProtonEnergyAfterEC = new TH1D("hProtonEnergyAfterEC", "The Energies of the Protons After Traversing the EC", 50, 0, 2500);
TH1D *hProtonAngleAfterEC = new TH1D("hProtonAngleAfterEC", "The Angles of the Protons After Traversing the EC", 60, 0, 180);

TH1D *hEnergyCheck1Scint0Steel = new TH1D("hEnergyCheck1Scint0Steel", "Checking the Energy After 1 Scint Layer and 0 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck1Scint0Steel = new TH1D("hAngleCheck1Scint0Steel", "Checking the Angle After 1 Scint Layer and 0 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck1Scint1Steel = new TH1D("hEnergyCheck1Scint1Steel", "Checking the Energy After 1 Scint Layer and 1 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck1Scint1Steel = new TH1D("hAngleCheck1Scint1Steel", "Checking the Angle After 1 Scint Layer and 1 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck2Scint1Steel = new TH1D("hEnergyCheck2Scint1Steel", "Checking the Energy After 2 Scint Layer and 1 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck2Scint1Steel = new TH1D("hAngleCheck2Scint1Steel", "Checking the Angle After 2 Scint Layer and 1 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck2Scint2Steel = new TH1D("hEnergyCheck2Scint2Steel", "Checking the Energy After 2 Scint Layer and 2 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck2Scint2Steel = new TH1D("hAngleCheck2Scint2Steel", "Checking the Angle After 2 Scint Layer and 2 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck3Scint2Steel = new TH1D("hEnergyCheck3Scint2Steel", "Checking the Energy After 3 Scint Layer and 2 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck3Scint2Steel = new TH1D("hAngleCheck3Scint2Steel", "Checking the Angle After 3 Scint Layer and 2 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck3Scint3Steel = new TH1D("hEnergyCheck3Scint3Steel", "Checking the Energy After 3 Scint Layer and 3 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck3Scint3Steel = new TH1D("hAngleCheck3Scint3Steel", "Checking the Angle After 3 Scint Layer and 3 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck4Scint3Steel = new TH1D("hEnergyCheck4Scint3Steel", "Checking the Energy After 4 Scint Layer and 3 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck4Scint3Steel = new TH1D("hAngleCheck4Scint3Steel", "Checking the Angle After 4 Scint Layer and 3 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck4Scint4Steel = new TH1D("hEnergyCheck4Scint4Steel", "Checking the Energy After 4 Scint Layer and 4 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck4Scint4Steel = new TH1D("hAngleCheck4Scint4Steel", "Checking the Angle After 4 Scint Layer and 4 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck5Scint4Steel = new TH1D("hEnergyCheck5Scint4Steel", "Checking the Energy After 5 Scint Layer and 4 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck5Scint4Steel = new TH1D("hAngleCheck5Scint4Steel", "Checking the Angle After 5 Scint Layer and 4 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck5Scint5Steel = new TH1D("hEnergyCheck5Scint5Steel", "Checking the Energy After 5 Scint Layer and 5 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck5Scint5Steel = new TH1D("hAngleCheck5Scint5Steel", "Checking the Angle After 5 Scint Layer and 5 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck6Scint5Steel = new TH1D("hEnergyCheck6Scint5Steel", "Checking the Energy After 6 Scint Layer and 5 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck6Scint5Steel = new TH1D("hAngleCheck6Scint5Steel", "Checking the Angle After 6 Scint Layer and 5 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck6Scint6Steel = new TH1D("hEnergyCheck6Scint6Steel", "Checking the Energy After 6 Scint Layer and 6 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck6Scint6Steel = new TH1D("hAngleCheck6Scint6Steel", "Checking the Angle After 6 Scint Layer and 6 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck7Scint6Steel = new TH1D("hEnergyCheck7Scint6Steel", "Checking the Energy After 7 Scint Layer and 6 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck7Scint6Steel = new TH1D("hAngleCheck7Scint6Steel", "Checking the Angle After 7 Scint Layer and 6 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck7Scint7Steel = new TH1D("hEnergyCheck7Scint7Steel", "Checking the Energy After 7 Scint Layer and 7 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck7Scint7Steel = new TH1D("hAngleCheck7Scint7Steel", "Checking the Angle After 7 Scint Layer and 7 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck8Scint7Steel = new TH1D("hEnergyCheck8Scint7Steel", "Checking the Energy After 8 Scint Layer and 7 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck8Scint7Steel = new TH1D("hAngleCheck8Scint7Steel", "Checking the Angle After 8 Scint Layer and 7 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck8Scint8Steel = new TH1D("hEnergyCheck8Scint8Steel", "Checking the Energy After 8 Scint Layer and 8 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck8Scint8Steel = new TH1D("hAngleCheck8Scint8Steel", "Checking the Angle After 8 Scint Layer and 8 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck9Scint8Steel = new TH1D("hEnergyCheck9Scint8Steel", "Checking the Energy After 9 Scint Layer and 8 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck9Scint8Steel = new TH1D("hAngleCheck9Scint8Steel", "Checking the Angle After 9 Scint Layer and 8 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck9Scint9Steel = new TH1D("hEnergyCheck9Scint9Steel", "Checking the Energy After 9 Scint Layer and 9 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck9Scint9Steel = new TH1D("hAngleCheck9Scint9Steel", "Checking the Angle After 9 Scint Layer and 9 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck10Scint9Steel = new TH1D("hEnergyCheck10Scint9Steel", "Checking the Energy After 10 Scint Layer and 9 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck10Scint9Steel = new TH1D("hAngleCheck10Scint9Steel", "Checking the Angle After 10 Scint Layer and 9 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck10Scint10Steel = new TH1D("hEnergyCheck10Scint10Steel", "Checking the Energy After 10 Scint Layer and 10 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck10Scint10Steel = new TH1D("hAngleCheck10Scint10Steel", "Checking the Angle After 10 Scint Layer and 10 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck11Scint10Steel = new TH1D("hEnergyCheck11Scint10Steel", "Checking the Energy After 11 Scint Layer and 10 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck11Scint10Steel = new TH1D("hAngleCheck11Scint10Steel", "Checking the Angle After 11 Scint Layer and 10 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck11Scint11Steel = new TH1D("hEnergyCheck11Scint11Steel", "Checking the Energy After 11 Scint Layer and 11 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck11Scint11Steel = new TH1D("hAngleCheck11Scint11Steel", "Checking the Angle After 11 Scint Layer and 11 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck12Scint11Steel = new TH1D("hEnergyCheck12Scint11Steel", "Checking the Energy After 12 Scint Layer and 11 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck12Scint11Steel = new TH1D("hAngleCheck12Scint11Steel", "Checking the Angle After 12 Scint Layer and 11 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck12Scint12Steel = new TH1D("hEnergyCheck12Scint12Steel", "Checking the Energy After 12 Scint Layer and 12 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck12Scint12Steel = new TH1D("hAngleCheck12Scint12Steel", "Checking the Angle After 12 Scint Layer and 12 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyCheck13Scint12Steel = new TH1D("hEnergyCheck13Scint12Steel", "Checking the Energy After 13 Scint Layer and 12 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck13Scint12Steel = new TH1D("hAngleCheck13Scint12Steel", "Checking the Angle After 13 Scint Layer and 12 Steel Layers of the MRD", 60, 0, 180);

TH1D *hEnergyTMMRD = new TH1D("hEnergyTMMRD", "Initial Energies of the Total Protons That Made it to the MRD", 50, 0, 2500);
TH1D *hMomentumTMMRD = new TH1D("hMomentumTMMRD", "Initial Momentums of the Total Protons That Made it to the MRD", 50, 0, 2500);
TH1D *hAngleTMMRD = new TH1D("hAngleTMMRD", "Initial Angles of the Total Protons That Made it to the MRD", 60, 0, 180);

TH1D *hEnergySNS = new TH1D("hEnergySNS", "Initial Energies of the Protons That Qualify as Stopped and Not-Stopped", 50, 0, 2500);
TH1D *hMomentumSNS = new TH1D("hMomentumSNS", "Initial Momentums of the Protons That Qualify as Stopped and Not-Stopped", 50, 0, 2500);
TH1D *hAngleSNS = new TH1D("hAngleSNS", "Initial Angles of the Protons That Qualify as Stopped and Not-Stopped", 60, 0, 180);

TH1D *hEnergyStopped = new TH1D("hEnergyStopped", "Initial Energies of the Stopped Protons", 50, 0, 2500);
TH1D *hMomentumStopped = new TH1D("hMomentumStopped", "Initial Momentums of the Stopped Protons", 50, 0, 2500);
TH1D *hAngleStopped = new TH1D("hAngleStopped", "Initial Angles of the Stopped Protons", 60, 0, 180);

TH1D *hEnergyNotStopped = new TH1D("hEnergyNotStopped", "Initial Energies of the Not-Stopped Protons", 50, 0, 2500);
TH1D *hMomentumNotStopped = new TH1D("hMomentumNotStopped", "Initial Momentums of the Not-Stopped Protons", 50, 0, 2500);
TH1D *hAngleNotStopped = new TH1D("hAngleNotStopped", "Initial Angles of the Not-Stopped Protons", 60, 0, 180);

TH1D *hEnergyOutSide = new TH1D("hEnergyOutSide", "Initial Energies of the Out the Side Protons", 50, 0, 2500);
TH1D *hMomentumOutSide = new TH1D("hMomentumOutSide", "Initial Momentums of the Out the Side Protons", 50, 0, 2500);
TH1D *hAngleOutSide = new TH1D("hAngleOutSide", "Initial Angles of the Out the Side Protons", 60, 0, 180);

TH2D *hTotalProton2D = new TH2D("hTotalProton2D", "Total 2D Histogram of Angle and Momentum for All Protons", 36, 0, 180, 45, 0, 4500);
TH2D *hSNSProton2D = new TH2D("hSNSProton2D", "2D Histogram of Angle and Momentum for Stopped and Not-Stopped Protons", 36, 0, 180, 45, 0, 4500);
//-----------------------------|


//-----------------------------|
//---  Constant Parameters  ---|
//-----------------------------|
int protonpdg = 2212; //Proton particle data group id number
double m_p = 938.272; //Proton mass in MeV

double SBx_0 = 0; //SciBar x initial in meters
double SBx_f = 3.0; //SciBar x final in meters
double SBy_0 = 0; //SciBar y initial in meters
double SBy_f = 3.0; //SciBar y final in meters
double SBz_0 = 0; //SciBar z initial in meters
double SBz_f = 1.7; //SciBar z final in meters

double SteelThickness = .0508; //Steel Layer Thickness of MRD in meters
double ScintThickness = .006; //Scint Layer Thickness of MRD in meters
double AirThickness = .06385; //Air Layer Thickness of MRD in meters
double DownstreamMRDFace = 0.55; //Location of MRD Downstream from SciBar in meters

double MRDx_0 = 0.2; //MRD x initial in meters
double MRDx_f = 2.8; //MRD x final in meters
double MRDy_0 = 0.2; //MRD y initial in meters
double MRDy_f = 2.4; //MRD y final in meters
double MRDz_0 = 0; //MRD z initial in meters
double MRDz_f = 1.402; //MRD z final in meters

double dEnergyLossECdTheta = 91; //Energy loss to EC in 91 MeV/cos(theta)
//-----------------------------|


//=============================|
//===     MPV Functions     ===|
//=============================|
double MPVCarbon(double x)
{
   
   double x0 = 0.2;
   double x1 = 3.0;
   double Cbar = 5.2146;
   double a = 0.19559;
   double k = 3.0;
   double K = 0.307075;
   double Z = 6;
   double A = 12.011;
   double m_e = 0.511;
   double M_proton = 938.272;
   double I = 79.1e-6;
   double width = 0.6;
   double rho = 2.265;
   double j = 0.2;
   double zeta = (K/2)*(Z/A)*width*rho;

   double MPV = (zeta*(M_proton*M_proton/x/x+1)*(log((2*m_e/I)*(x*x/M_proton/M_proton))+log(zeta/I*(M_proton*M_proton/x/x+1))+0.2-(1/(M_proton*M_proton/x/x+1))-((x<M_proton*exp(0.2*log(10)))*0+(M_proton*exp(0.2*log(10))<=x && x<M_proton*exp(3.0*log(10)))*(2*log(x/M_proton)-Cbar+a*pow(x1-log(x/M_proton)/log(10),3.))+(x>=M_proton*exp(3.0*log(10)))*(2*log(x/M_proton)-Cbar)))/(width*rho)) * rho;
   return MPV;

} //<--- Close MPV on Carbon function


double MPVSteel(double x)
{
   
   double x0 = 0.2;
   double x1 = 3.0;
   double Cbar = 5.2146;
   double a = 0.19559;
   double k = 3.0;
   double K = 0.307075;
   double Z = 26;
   double A = 55.845;
   double m_e = 0.511;
   double M_proton = 938.272;
   double I = 286e-6;
   double width = 5.08;
   double rho = 7.87;
   double j = 0.2;
   double zeta = (K/2)*(Z/A)*width*rho;

   double MPV = (zeta*(M_proton*M_proton/x/x+1)*(log((2*m_e/I)*(x*x/M_proton/M_proton))+log(zeta/I*(M_proton*M_proton/x/x+1))+0.2-(1/(M_proton*M_proton/x/x+1))-((x<M_proton*exp(0.2*log(10)))*0+(M_proton*exp(0.2*log(10))<=x && x<M_proton*exp(3.0*log(10)))*(2*log(x/M_proton)-Cbar+a*pow(x1-log(x/M_proton)/log(10),3.))+(x>=M_proton*exp(3.0*log(10)))*(2*log(x/M_proton)-Cbar)))/(width*rho)) * rho;
   return MPV;

} //<--- Close MPV on Steel function
//=============================|


//===========================================|
//              Event Selection              |
//===========================================|
void NewANMRSProton::Loop()
{

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;

   //----------------------------------------|
   //---     Event Counters/Register      ---|
   //----------------------------------------|
   int nEvents = 0;
   int nEventsWithProton = 0;
   int nProtons = 0;
   int ProtonRegister = 99;

   int nMRDFace = 0;
   int nMRDBack = 0;
   int nOutSciBar = 0;
   int nOutEC = 0;
   int nMadeMRD = 0;

   int nOutSide = 0;
   int nStopped = 0;
   int nNotStopped = 0;
   //----------------------------------------|

   for (Long64_t jentry=0; jentry<nentries; jentry++)
   {

      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      nEvents++;
      if (nEvents%1000 == 0) {std::cout<<"Event = "<<nEvents<<std::endl;} //Event print out every 1000 events

      TRandom3 *randX = new TRandom3();
      TRandom3 *randY = new TRandom3();
      TRandom3 *flat = new TRandom3();
      randX->SetSeed(jentry/2);
      randY->SetSeed(jentry*jentry);
      flat->SetSeed(jentry*jentry*jentry);
      double Xpos = randX->Gaus(1.5,1.3);
      while (Xpos<0 || Xpos>3.0) { Xpos = randX->Gaus(1.5,1.3); }
      double Ypos = randY->Gaus(1.5,1.05);
      while (Ypos<0 || Ypos>3.0) { Ypos = randY->Gaus(1.5,1.05); }
      double Zpos = flat->Uniform(0,1.7);

      for (int npart=0; npart<StdHepN; npart++)
      {

         if (StdHepPdg[npart] == protonpdg && StdHepStatus[npart] == 1 && StdHepP4[npart][2] > 0) 
	 {

            nProtons++;

	    if (nProtons == 1)
            {

	       ProtonRegister = npart;

	    } //<--- Close Initial Register set if statement


	    if (nProtons >= 2)
	    {
   
               double Check = StdHepP4[ProtonRegister][2] - StdHepP4[npart][2];
	       if (Check <= 0) {ProtonRegister = npart;}

	    } //<--- Close finding most boosted proton of event if statement


	 } //<--- Close if statement


      } //<--- Close loop over particles in event


      if (nProtons > 0 && StdHepP4[ProtonRegister][2] > 0 && StdHepP4[ProtonRegister][3]*1000 > m_p) 
      {

         nEventsWithProton++;

	 TVector3 momentum(StdHepP4[ProtonRegister][0],StdHepP4[ProtonRegister][1],StdHepP4[ProtonRegister][2]); //Initial Proton Momentum
	 TVector3 direction(momentum.X()/momentum.Mag(),momentum.Y()/momentum.Mag(),momentum.Z()/momentum.Mag()); //Unit vector of Proton Momentum (direction Proton is going)
	 TVector3 position(Xpos,Ypos,Zpos); //Initial Proton Position

         hTotalProtonEnergy->Fill(StdHepP4[ProtonRegister][3]*1000);
	 hTotalProtonMomentum->Fill(momentum.Mag()*1000);
	 hTotalProtonAngle->Fill(momentum.Theta()*180/PI);
	 hTotalProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
         
	 double ProtonEnergy = 1000*StdHepP4[ProtonRegister][3]; //Initial Proton Energy
	 Double_t m_i = momentum.Mag(); //Initial Proton Momentum

	 double ProtonTimeZSBEnd = (SBz_f - position.Z())/momentum.Z();
	 double ProtonTimeZMRDFace = (SBz_f + DownstreamMRDFace - position.Z())/momentum.Z();
	 double ProtonTimeZMRDBack = (SBz_f + DownstreamMRDFace + MRDz_f - position.Z())/momentum.Z();

         double DeltaXMRDFace = momentum.X()*ProtonTimeZMRDFace;
	 double DeltaYMRDFace = momentum.Y()*ProtonTimeZMRDFace;

	 double DeltaXMRDBack = momentum.X()*ProtonTimeZMRDBack;
	 double DeltaYMRDBack = momentum.Y()*ProtonTimeZMRDBack;

	 double XposMRDFace = DeltaXMRDFace + position.X();
	 double YposMRDFace = DeltaYMRDFace + position.Y();
	 
	 double XposMRDBack = DeltaXMRDBack + position.X();
	 double YposMRDBack = DeltaYMRDBack + position.Y();

	 if ((XposMRDFace >= MRDx_0) && (XposMRDFace <= MRDx_f) && (YposMRDFace >= MRDy_0) && (YposMRDFace <= MRDy_f)) 
	 {
		 
            nMRDFace++;

            double DeltaXSBEnd = momentum.X()*ProtonTimeZSBEnd;
	    double DeltaYSBEnd = momentum.Y()*ProtonTimeZSBEnd;

	    double XposSBEnd = DeltaXSBEnd + position.X();
	    double YposSBEnd = DeltaYSBEnd + position.Y();

	    double LengthThroughSciBar = sqrt((DeltaXSBEnd*DeltaXSBEnd) + (DeltaYSBEnd*DeltaYSBEnd) + ((SBz_f - position.Z())*(SBz_f - position.Z())));

	    double EnergyAfterSciBar = ProtonEnergy - LengthThroughSciBar*MPVCarbon(1000*momentum.Mag())*100;

	    if (EnergyAfterSciBar > m_p) 
	    {

	       hProtonEnergyAfterSciBar->Fill(EnergyAfterSciBar);
	       hProtonAngleAfterSciBar->Fill(momentum.Theta()*180/PI);
	       nOutSciBar++;

	       double EnergyAfterEC = EnergyAfterSciBar - dEnergyLossECdTheta*cos(momentum.Theta());
	       if (EnergyAfterEC > m_p)
	       {

                  hProtonEnergyAfterEC->Fill(EnergyAfterEC);
		  hProtonAngleAfterEC->Fill(momentum.Theta()*180/PI);
		  nOutEC++;
		  //nMadeMRD++;

		  double MomMag = sqrt(EnergyAfterEC*EnergyAfterEC - m_p*m_p);
		  TVector3 ProtonMomentum(MomMag*direction.X(),MomMag*direction.Y(),MomMag*direction.Z());
		  TVector3 MRDFacePosition(XposMRDFace,YposMRDFace,SBz_f+DownstreamMRDFace);

		  TVector3 WorkingPosition(MRDFacePosition.X(),MRDFacePosition.Y(),MRDFacePosition.Z());

		  double rangeScint = ScintThickness/cos(momentum.Theta());
		  double rangeSteel = SteelThickness/cos(momentum.Theta());
		  double rangeAir = AirThickness/cos(momentum.Theta());

		  TVector3 DeltaScint(rangeScint*direction.X(),rangeScint*direction.Y(),rangeScint*direction.Z());
		  TVector3 DeltaSteel(rangeSteel*direction.X(),rangeSteel*direction.Y(),rangeSteel*direction.Z());
		  TVector3 DeltaAir(rangeAir*direction.X(),rangeAir*direction.Y(),rangeAir*direction.Z());

		  double EnergyAfter1Scint0Steel = EnergyAfterEC - MPVCarbon(ProtonMomentum.Mag())*100*rangeScint;

		  WorkingPosition.SetX(MRDFacePosition.X() + 1*DeltaScint.X() + 0*DeltaSteel.X() + 0*DeltaAir.X());
		  WorkingPosition.SetY(MRDFacePosition.Y() + 1*DeltaScint.Y() + 0*DeltaSteel.Y() + 0*DeltaAir.Y());
		  WorkingPosition.SetZ(MRDFacePosition.Z() + 1*DeltaScint.Z() + 0*DeltaSteel.Z() + 0*DeltaAir.Z());

		  if ((MRDx_f > MRDFacePosition.X() > MRDx_0) && (MRDy_f > MRDFacePosition.Y() > MRDy_0)) 
		  {

	             nMadeMRD++;
                     hEnergyTMMRD->Fill(ProtonEnergy);
		     hMomentumTMMRD->Fill(momentum.Mag()*1000);
		     hAngleTMMRD->Fill(momentum.Theta()*180/PI);

		  }

		  if ((EnergyAfter1Scint0Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
		  {

		     nStopped++;
		     hEnergySNS->Fill(ProtonEnergy);
		     hMomentumSNS->Fill(momentum.Mag()*1000);
		     hAngleSNS->Fill(momentum.Theta()*180/PI);
		     hEnergyStopped->Fill(ProtonEnergy);
		     hMomentumStopped->Fill(momentum.Mag()*1000);
		     hAngleStopped->Fill(momentum.Theta()*180/PI);
		     hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);

		  }

		  if ((EnergyAfter1Scint0Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
		  {

                     hEnergyCheck1Scint0Steel->Fill(EnergyAfter1Scint0Steel);
		     hAngleCheck1Scint0Steel->Fill(momentum.Theta()*180/PI);

		     MomMag = sqrt(EnergyAfter1Scint0Steel*EnergyAfter1Scint0Steel - m_p*m_p);

		     double EnergyAfter1Scint1Steel = EnergyAfter1Scint0Steel - MPVSteel(MomMag)*100*rangeSteel;// - MPVCarbon(MomMag)*100*rangeSteel;

		     WorkingPosition.SetX(MRDFacePosition.X() + 1*DeltaScint.X() + 1*DeltaSteel.X() + 0*DeltaAir.X());
		     WorkingPosition.SetY(MRDFacePosition.Y() + 1*DeltaScint.Y() + 1*DeltaSteel.Y() + 0*DeltaAir.Y());
		     WorkingPosition.SetZ(MRDFacePosition.Z() + 1*DeltaScint.Z() + 1*DeltaSteel.Z() + 0*DeltaAir.Z());

		     if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter1Scint1Steel > m_p)) 
		     {

		        nOutSide++;
                        hEnergyOutSide->Fill(ProtonEnergy);
                        hMomentumOutSide->Fill(momentum.Mag()*1000);
                        hAngleOutSide->Fill(momentum.Theta()*180/PI);

		     }

		     if ((EnergyAfter1Scint1Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
		     {

		        nStopped++;
		        hEnergySNS->Fill(ProtonEnergy);
			hMomentumSNS->Fill(momentum.Mag()*1000);
		        hAngleSNS->Fill(momentum.Theta()*180/PI);
		        hEnergyStopped->Fill(ProtonEnergy);
			hMomentumStopped->Fill(momentum.Mag()*1000);
		        hAngleStopped->Fill(momentum.Theta()*180/PI);
			hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
		     
		     }

		     if ((EnergyAfter1Scint1Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
		     {

                        hEnergyCheck1Scint1Steel->Fill(EnergyAfter1Scint1Steel);
			hAngleCheck1Scint1Steel->Fill(momentum.Theta()*180/PI);

		        MomMag = sqrt(EnergyAfter1Scint1Steel*EnergyAfter1Scint1Steel - m_p*m_p);

		        double EnergyAfter2Scint1Steel = EnergyAfter1Scint1Steel - MPVCarbon(MomMag)*100*rangeScint;

		        WorkingPosition.SetX(MRDFacePosition.X() + 2*DeltaScint.X() + 1*DeltaSteel.X() + 0*DeltaAir.X());
		        WorkingPosition.SetY(MRDFacePosition.Y() + 2*DeltaScint.Y() + 1*DeltaSteel.Y() + 0*DeltaAir.Y());
		        WorkingPosition.SetZ(MRDFacePosition.Z() + 2*DeltaScint.Z() + 1*DeltaSteel.Z() + 0*DeltaAir.Z());

		        if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter2Scint1Steel > m_p)) 
			{

		           nOutSide++;
                           hEnergyOutSide->Fill(ProtonEnergy);
                           hMomentumOutSide->Fill(momentum.Mag()*1000);
                           hAngleOutSide->Fill(momentum.Theta()*180/PI);

			}

		        if ((EnergyAfter2Scint1Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
			{

			   nStopped++;
		           hEnergySNS->Fill(ProtonEnergy);
			   hMomentumSNS->Fill(momentum.Mag()*1000);
		           hAngleSNS->Fill(momentum.Theta()*180/PI);
		           hEnergyStopped->Fill(ProtonEnergy);
			   hMomentumStopped->Fill(momentum.Mag()*1000);
		           hAngleStopped->Fill(momentum.Theta()*180/PI);
			   hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);

			}

		        if ((EnergyAfter2Scint1Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			{

                           hEnergyCheck2Scint1Steel->Fill(EnergyAfter2Scint1Steel);
			   hAngleCheck2Scint1Steel->Fill(momentum.Theta()*180/PI);

		           MomMag = sqrt(EnergyAfter2Scint1Steel*EnergyAfter2Scint1Steel - m_p*m_p);

		           double EnergyAfter2Scint2Steel = EnergyAfter2Scint1Steel - MPVSteel(MomMag)*100*rangeSteel;// - MPVCarbon(MomMag)*100*rangeSteel;

		           WorkingPosition.SetX(MRDFacePosition.X() + 2*DeltaScint.X() + 2*DeltaSteel.X() + 1*DeltaAir.X());
		           WorkingPosition.SetY(MRDFacePosition.Y() + 2*DeltaScint.Y() + 2*DeltaSteel.Y() + 1*DeltaAir.Y());
		           WorkingPosition.SetZ(MRDFacePosition.Z() + 2*DeltaScint.Z() + 2*DeltaSteel.Z() + 1*DeltaAir.Z());

		           if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter2Scint2Steel > m_p)) 
			   {

			      nOutSide++;
                              hEnergyOutSide->Fill(ProtonEnergy);
                              hMomentumOutSide->Fill(momentum.Mag()*1000);
                              hAngleOutSide->Fill(momentum.Theta()*180/PI);

			   }

		           if ((EnergyAfter2Scint2Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
			   {

			      nStopped++;
		              hEnergySNS->Fill(ProtonEnergy);
			      hMomentumSNS->Fill(momentum.Mag()*1000);
		              hAngleSNS->Fill(momentum.Theta()*180/PI);
		              hEnergyStopped->Fill(ProtonEnergy);
			      hMomentumStopped->Fill(momentum.Mag()*1000);
		              hAngleStopped->Fill(momentum.Theta()*180/PI);
			      hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);

			   }

		           if ((EnergyAfter2Scint2Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			   {

                              hEnergyCheck2Scint2Steel->Fill(EnergyAfter2Scint2Steel);
			      hAngleCheck2Scint2Steel->Fill(momentum.Theta()*180/PI);

		              MomMag = sqrt(EnergyAfter2Scint2Steel*EnergyAfter2Scint2Steel - m_p*m_p);

		              double EnergyAfter3Scint2Steel = EnergyAfter2Scint2Steel - MPVCarbon(MomMag)*100*rangeScint;

		              WorkingPosition.SetX(MRDFacePosition.X() + 3*DeltaScint.X() + 2*DeltaSteel.X() + 1*DeltaAir.X());
		              WorkingPosition.SetY(MRDFacePosition.Y() + 3*DeltaScint.Y() + 2*DeltaSteel.Y() + 1*DeltaAir.Y());
		              WorkingPosition.SetZ(MRDFacePosition.Z() + 3*DeltaScint.Z() + 2*DeltaSteel.Z() + 1*DeltaAir.Z());

		              if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter3Scint2Steel > m_p)) 
			      {

			         nOutSide++;
                                 hEnergyOutSide->Fill(ProtonEnergy);
                                 hMomentumOutSide->Fill(momentum.Mag()*1000);
                                 hAngleOutSide->Fill(momentum.Theta()*180/PI);

			      }

		              if ((EnergyAfter3Scint2Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
			      {

			         nStopped++;
		                 hEnergySNS->Fill(ProtonEnergy);
			         hMomentumSNS->Fill(momentum.Mag()*1000);
		                 hAngleSNS->Fill(momentum.Theta()*180/PI);
		                 hEnergyStopped->Fill(ProtonEnergy);
			         hMomentumStopped->Fill(momentum.Mag()*1000);
		                 hAngleStopped->Fill(momentum.Theta()*180/PI);
				 hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);

			      }

		              if ((EnergyAfter3Scint2Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			      {

                                 hEnergyCheck3Scint2Steel->Fill(EnergyAfter3Scint2Steel);
			         hAngleCheck3Scint2Steel->Fill(momentum.Theta()*180/PI);

		                 MomMag = sqrt(EnergyAfter3Scint2Steel*EnergyAfter3Scint2Steel - m_p*m_p);

		                 double EnergyAfter3Scint3Steel = EnergyAfter3Scint2Steel - MPVSteel(MomMag)*100*rangeSteel;// - MPVCarbon(MomMag)*100*rangeSteel;

		                 WorkingPosition.SetX(MRDFacePosition.X() + 3*DeltaScint.X() + 3*DeltaSteel.X() + 2*DeltaAir.X());
		                 WorkingPosition.SetY(MRDFacePosition.Y() + 3*DeltaScint.Y() + 3*DeltaSteel.Y() + 2*DeltaAir.Y());
		                 WorkingPosition.SetZ(MRDFacePosition.Z() + 3*DeltaScint.Z() + 3*DeltaSteel.Z() + 2*DeltaAir.Z());

		                 if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter3Scint3Steel > m_p)) 
				 {

			            nOutSide++;
                                    hEnergyOutSide->Fill(ProtonEnergy);
                                    hMomentumOutSide->Fill(momentum.Mag()*1000);
                                    hAngleOutSide->Fill(momentum.Theta()*180/PI);
				 
				 }

		                 if ((EnergyAfter3Scint3Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
				 {
					 
				    nStopped++;
		                    hEnergySNS->Fill(ProtonEnergy);
			            hMomentumSNS->Fill(momentum.Mag()*1000);
		                    hAngleSNS->Fill(momentum.Theta()*180/PI);
		                    hEnergyStopped->Fill(ProtonEnergy);
			            hMomentumStopped->Fill(momentum.Mag()*1000);
		                    hAngleStopped->Fill(momentum.Theta()*180/PI);
				    hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
				 
				 }

		                 if ((EnergyAfter3Scint3Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			         {

                                    hEnergyCheck3Scint3Steel->Fill(EnergyAfter3Scint3Steel);
			            hAngleCheck3Scint3Steel->Fill(momentum.Theta()*180/PI);

		                    MomMag = sqrt(EnergyAfter3Scint3Steel*EnergyAfter3Scint3Steel - m_p*m_p);

		                    double EnergyAfter4Scint3Steel = EnergyAfter3Scint3Steel - MPVCarbon(MomMag)*100*rangeScint;

		                    WorkingPosition.SetX(MRDFacePosition.X() + 4*DeltaScint.X() + 3*DeltaSteel.X() + 2*DeltaAir.X());
		                    WorkingPosition.SetY(MRDFacePosition.Y() + 4*DeltaScint.Y() + 3*DeltaSteel.Y() + 2*DeltaAir.Y());
		                    WorkingPosition.SetZ(MRDFacePosition.Z() + 4*DeltaScint.Z() + 3*DeltaSteel.Z() + 2*DeltaAir.Z());

		                    if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter4Scint3Steel > m_p)) 
				    {
					    
				       nOutSide++;
                                       hEnergyOutSide->Fill(ProtonEnergy);
                                       hMomentumOutSide->Fill(momentum.Mag()*1000);
                                       hAngleOutSide->Fill(momentum.Theta()*180/PI);
				    
				    }

		                    if ((EnergyAfter4Scint3Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
				    {
					    
				       nStopped++;
		                       hEnergySNS->Fill(ProtonEnergy);
			               hMomentumSNS->Fill(momentum.Mag()*1000);
		     		       hAngleSNS->Fill(momentum.Theta()*180/PI);
		     		       hEnergyStopped->Fill(ProtonEnergy);
			               hMomentumStopped->Fill(momentum.Mag()*1000);
		     		       hAngleStopped->Fill(momentum.Theta()*180/PI);
				       hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
				    
				    }

		                    if ((EnergyAfter4Scint3Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			            {

                                       hEnergyCheck4Scint3Steel->Fill(EnergyAfter4Scint3Steel);
			               hAngleCheck4Scint3Steel->Fill(momentum.Theta()*180/PI);

		                       MomMag = sqrt(EnergyAfter4Scint3Steel*EnergyAfter4Scint3Steel - m_p*m_p);

		                       double EnergyAfter4Scint4Steel = EnergyAfter4Scint3Steel - MPVSteel(MomMag)*100*rangeSteel;// - MPVCarbon(MomMag)*100*rangeSteel;

		                       WorkingPosition.SetX(MRDFacePosition.X() + 4*DeltaScint.X() + 4*DeltaSteel.X() + 3*DeltaAir.X());
		                       WorkingPosition.SetY(MRDFacePosition.Y() + 4*DeltaScint.Y() + 4*DeltaSteel.Y() + 3*DeltaAir.Y());
		                       WorkingPosition.SetZ(MRDFacePosition.Z() + 4*DeltaScint.Z() + 4*DeltaSteel.Z() + 3*DeltaAir.Z());

		                       if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter4Scint4Steel > m_p)) 
				       {
					       
				          nOutSide++;
                                          hEnergyOutSide->Fill(ProtonEnergy);
                                          hMomentumOutSide->Fill(momentum.Mag()*1000);
                                          hAngleOutSide->Fill(momentum.Theta()*180/PI);
				       
				       }

		                       if ((EnergyAfter4Scint4Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
				       {
					       
			  	          nStopped++;
		        		  hEnergySNS->Fill(ProtonEnergy);
			                  hMomentumSNS->Fill(momentum.Mag()*1000);
		     			  hAngleSNS->Fill(momentum.Theta()*180/PI);
		     			  hEnergyStopped->Fill(ProtonEnergy);
			                  hMomentumStopped->Fill(momentum.Mag()*1000);
		     			  hAngleStopped->Fill(momentum.Theta()*180/PI);
					  hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
				       
				       }

		                       if ((EnergyAfter4Scint4Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			               {

                                          hEnergyCheck4Scint4Steel->Fill(EnergyAfter4Scint4Steel);
			                  hAngleCheck4Scint4Steel->Fill(momentum.Theta()*180/PI);

		                          MomMag = sqrt(EnergyAfter4Scint4Steel*EnergyAfter4Scint4Steel - m_p*m_p);

		                          double EnergyAfter5Scint4Steel = EnergyAfter4Scint4Steel - MPVCarbon(MomMag)*100*rangeScint;

		                          WorkingPosition.SetX(MRDFacePosition.X() + 5*DeltaScint.X() + 4*DeltaSteel.X() + 3*DeltaAir.X());
		                          WorkingPosition.SetY(MRDFacePosition.Y() + 5*DeltaScint.Y() + 4*DeltaSteel.Y() + 3*DeltaAir.Y());
		                          WorkingPosition.SetZ(MRDFacePosition.Z() + 5*DeltaScint.Z() + 4*DeltaSteel.Z() + 3*DeltaAir.Z());

		                          if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter5Scint4Steel > m_p)) 
					  {
						  
				  	     nOutSide++;
                                             hEnergyOutSide->Fill(ProtonEnergy);
                                             hMomentumOutSide->Fill(momentum.Mag()*1000);
                                             hAngleOutSide->Fill(momentum.Theta()*180/PI);
					  
					  }

		                          if ((EnergyAfter5Scint4Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
					  {
						  
			     	             nStopped++;
		                             hEnergySNS->Fill(ProtonEnergy);
			                     hMomentumSNS->Fill(momentum.Mag()*1000);
		           		     hAngleSNS->Fill(momentum.Theta()*180/PI);
		           		     hEnergyStopped->Fill(ProtonEnergy);
			                     hMomentumStopped->Fill(momentum.Mag()*1000);
		          		     hAngleStopped->Fill(momentum.Theta()*180/PI);
					     hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
					  
					  }

		                          if ((EnergyAfter5Scint4Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                  {

                                             hEnergyCheck5Scint4Steel->Fill(EnergyAfter5Scint4Steel);
			                     hAngleCheck5Scint4Steel->Fill(momentum.Theta()*180/PI);

		                             MomMag = sqrt(EnergyAfter5Scint4Steel*EnergyAfter5Scint4Steel - m_p*m_p);

		                             double EnergyAfter5Scint5Steel = EnergyAfter5Scint4Steel - MPVSteel(MomMag)*100*rangeSteel;

		                             WorkingPosition.SetX(MRDFacePosition.X() + 5*DeltaScint.X() + 5*DeltaSteel.X() + 4*DeltaAir.X());
		                             WorkingPosition.SetY(MRDFacePosition.Y() + 5*DeltaScint.Y() + 5*DeltaSteel.Y() + 4*DeltaAir.Y());
		                             WorkingPosition.SetZ(MRDFacePosition.Z() + 5*DeltaScint.Z() + 5*DeltaSteel.Z() + 4*DeltaAir.Z());

		                             if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter5Scint5Steel > m_p)) 
					     {
						     
					        nOutSide++;
                                                hEnergyOutSide->Fill(ProtonEnergy);
                                                hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                hAngleOutSide->Fill(momentum.Theta()*180/PI);
					     
					     }

		                             if ((EnergyAfter5Scint5Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
					     {
						     
				 	        nStopped++;
		           			hEnergySNS->Fill(ProtonEnergy);
			                        hMomentumSNS->Fill(momentum.Mag()*1000);
		           			hAngleSNS->Fill(momentum.Theta()*180/PI);
		           			hEnergyStopped->Fill(ProtonEnergy);
			                        hMomentumStopped->Fill(momentum.Mag()*1000);
		           			hAngleStopped->Fill(momentum.Theta()*180/PI);
						hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
					     
					     }

		                             if ((EnergyAfter5Scint5Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                     {

                                                hEnergyCheck5Scint5Steel->Fill(EnergyAfter5Scint5Steel);
			                        hAngleCheck5Scint5Steel->Fill(momentum.Theta()*180/PI);

		                                MomMag = sqrt(EnergyAfter5Scint5Steel*EnergyAfter5Scint5Steel - m_p*m_p);

		                                double EnergyAfter6Scint5Steel = EnergyAfter5Scint5Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                WorkingPosition.SetX(MRDFacePosition.X() + 6*DeltaScint.X() + 5*DeltaSteel.X() + 4*DeltaAir.X());
		                                WorkingPosition.SetY(MRDFacePosition.Y() + 6*DeltaScint.Y() + 5*DeltaSteel.Y() + 4*DeltaAir.Y());
		                                WorkingPosition.SetZ(MRDFacePosition.Z() + 6*DeltaScint.Z() + 5*DeltaSteel.Z() + 4*DeltaAir.Z());

		                                if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter6Scint5Steel > m_p)) 
						{
							
						   nOutSide++;
                                                   hEnergyOutSide->Fill(ProtonEnergy);
                                                   hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                   hAngleOutSide->Fill(momentum.Theta()*180/PI);
						
						}

		                                if ((EnergyAfter6Scint5Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
						{
							
						   nStopped++;
		           			   hEnergySNS->Fill(ProtonEnergy);
			                           hMomentumSNS->Fill(momentum.Mag()*1000);
		           			   hAngleSNS->Fill(momentum.Theta()*180/PI);
		           			   hEnergyStopped->Fill(ProtonEnergy);
			                           hMomentumStopped->Fill(momentum.Mag()*1000);
		           			   hAngleStopped->Fill(momentum.Theta()*180/PI);
						   hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
						
						}

		                                if ((EnergyAfter6Scint5Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                        {

                                                   hEnergyCheck6Scint5Steel->Fill(EnergyAfter6Scint5Steel);
			                           hAngleCheck6Scint5Steel->Fill(momentum.Theta()*180/PI);

		                                   MomMag = sqrt(EnergyAfter6Scint5Steel*EnergyAfter6Scint5Steel - m_p*m_p);

		                                   double EnergyAfter6Scint6Steel = EnergyAfter6Scint5Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                   WorkingPosition.SetX(MRDFacePosition.X() + 6*DeltaScint.X() + 6*DeltaSteel.X() + 5*DeltaAir.X());
		                                   WorkingPosition.SetY(MRDFacePosition.Y() + 6*DeltaScint.Y() + 6*DeltaSteel.Y() + 5*DeltaAir.Y());
		                                   WorkingPosition.SetZ(MRDFacePosition.Z() + 6*DeltaScint.Z() + 6*DeltaSteel.Z() + 5*DeltaAir.Z());

		                                   if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter6Scint6Steel > m_p)) 
						   {
							   
						      nOutSide++;
                                                      hEnergyOutSide->Fill(ProtonEnergy);
                                                      hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                      hAngleOutSide->Fill(momentum.Theta()*180/PI);
						   
						   }

		                                   if ((EnergyAfter6Scint6Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
						   {
							   
						      nStopped++;
		           			      hEnergySNS->Fill(ProtonEnergy);
			                              hMomentumSNS->Fill(momentum.Mag()*1000);
		           			      hAngleSNS->Fill(momentum.Theta()*180/PI);
		          			      hEnergyStopped->Fill(ProtonEnergy);
			                              hMomentumStopped->Fill(momentum.Mag()*1000);
		          			      hAngleStopped->Fill(momentum.Theta()*180/PI);
						      hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
						   
						   }

		                                   if ((EnergyAfter6Scint6Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                           {

                                                      hEnergyCheck6Scint6Steel->Fill(EnergyAfter6Scint6Steel);
			                              hAngleCheck6Scint6Steel->Fill(momentum.Theta()*180/PI);

		                                      MomMag = sqrt(EnergyAfter6Scint6Steel*EnergyAfter6Scint6Steel - m_p*m_p);

		                                      double EnergyAfter7Scint6Steel = EnergyAfter6Scint6Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                      WorkingPosition.SetX(MRDFacePosition.X() + 7*DeltaScint.X() + 6*DeltaSteel.X() + 5*DeltaAir.X());
		                                      WorkingPosition.SetY(MRDFacePosition.Y() + 7*DeltaScint.Y() + 6*DeltaSteel.Y() + 5*DeltaAir.Y());
		                                      WorkingPosition.SetZ(MRDFacePosition.Z() + 7*DeltaScint.Z() + 6*DeltaSteel.Z() + 5*DeltaAir.Z());

		                                      if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter7Scint6Steel > m_p)) 
						      {
							      
						         nOutSide++;
                                                         hEnergyOutSide->Fill(ProtonEnergy);
                                                         hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                         hAngleOutSide->Fill(momentum.Theta()*180/PI);
						      
						      }

		                                      if ((EnergyAfter7Scint6Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
						      {
							      
						         nStopped++;
		           				 hEnergySNS->Fill(ProtonEnergy);
			                                 hMomentumSNS->Fill(momentum.Mag()*1000);
		           				 hAngleSNS->Fill(momentum.Theta()*180/PI);
		           				 hEnergyStopped->Fill(ProtonEnergy);
			                                 hMomentumStopped->Fill(momentum.Mag()*1000);
		          				 hAngleStopped->Fill(momentum.Theta()*180/PI);
							 hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
						      
						      }

		                                      if ((EnergyAfter7Scint6Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                              {

                                                         hEnergyCheck7Scint6Steel->Fill(EnergyAfter7Scint6Steel);
			                                 hAngleCheck7Scint6Steel->Fill(momentum.Theta()*180/PI);

		                                         MomMag = sqrt(EnergyAfter7Scint6Steel*EnergyAfter7Scint6Steel - m_p*m_p);

		                                         double EnergyAfter7Scint7Steel = EnergyAfter7Scint6Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                         WorkingPosition.SetX(MRDFacePosition.X() + 7*DeltaScint.X() + 7*DeltaSteel.X() + 6*DeltaAir.X());
		                                         WorkingPosition.SetY(MRDFacePosition.Y() + 7*DeltaScint.Y() + 7*DeltaSteel.Y() + 6*DeltaAir.Y());
		                                         WorkingPosition.SetZ(MRDFacePosition.Z() + 7*DeltaScint.Z() + 7*DeltaSteel.Z() + 6*DeltaAir.Z());

		                                         if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter7Scint7Steel > m_p)) 
							 {
								 
							    nOutSide++;
                                                            hEnergyOutSide->Fill(ProtonEnergy);
                                                            hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                            hAngleOutSide->Fill(momentum.Theta()*180/PI);
							 
							 }

		                                         if ((EnergyAfter7Scint7Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
							 {
								 
							    nStopped++;
		           				    hEnergySNS->Fill(ProtonEnergy);
			                                    hMomentumSNS->Fill(momentum.Mag()*1000);
		           				    hAngleSNS->Fill(momentum.Theta()*180/PI);
		           				    hEnergyStopped->Fill(ProtonEnergy);
			                                    hMomentumStopped->Fill(momentum.Mag()*1000);
		           				    hAngleStopped->Fill(momentum.Theta()*180/PI);
							    hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
							 
							 }

		                                         if ((EnergyAfter7Scint7Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                 {

                                                            hEnergyCheck7Scint7Steel->Fill(EnergyAfter7Scint7Steel);
			                                    hAngleCheck7Scint7Steel->Fill(momentum.Theta()*180/PI);

		                                            MomMag = sqrt(EnergyAfter7Scint7Steel*EnergyAfter7Scint7Steel - m_p*m_p);

		                                            double EnergyAfter8Scint7Steel = EnergyAfter7Scint7Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                            WorkingPosition.SetX(MRDFacePosition.X() + 8*DeltaScint.X() + 7*DeltaSteel.X() + 6*DeltaAir.X());
		                                            WorkingPosition.SetY(MRDFacePosition.Y() + 8*DeltaScint.Y() + 7*DeltaSteel.Y() + 6*DeltaAir.Y());
		                                            WorkingPosition.SetZ(MRDFacePosition.Z() + 8*DeltaScint.Z() + 7*DeltaSteel.Z() + 6*DeltaAir.Z());

		                                            if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter8Scint7Steel > m_p)) 
							    {
								    
							       nOutSide++;
                                                               hEnergyOutSide->Fill(ProtonEnergy);
                                                               hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                               hAngleOutSide->Fill(momentum.Theta()*180/PI);
							    
							    }

		                                            if ((EnergyAfter8Scint7Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
							    {
								   
							       nStopped++;
		           				       hEnergySNS->Fill(ProtonEnergy);
			                                       hMomentumSNS->Fill(momentum.Mag()*1000);
		           				       hAngleSNS->Fill(momentum.Theta()*180/PI);
		           				       hEnergyStopped->Fill(ProtonEnergy);
			                                       hMomentumStopped->Fill(momentum.Mag()*1000);
		           				       hAngleStopped->Fill(momentum.Theta()*180/PI);
							       hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
							    
							    }

		                                            if ((EnergyAfter8Scint7Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                    {

                                                               hEnergyCheck8Scint7Steel->Fill(EnergyAfter8Scint7Steel);
			                                       hAngleCheck8Scint7Steel->Fill(momentum.Theta()*180/PI);

		                                               MomMag = sqrt(EnergyAfter8Scint7Steel*EnergyAfter8Scint7Steel - m_p*m_p);

		                                               double EnergyAfter8Scint8Steel = EnergyAfter8Scint7Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                               WorkingPosition.SetX(MRDFacePosition.X() + 8*DeltaScint.X() + 8*DeltaSteel.X() + 7*DeltaAir.X());
		                                               WorkingPosition.SetY(MRDFacePosition.Y() + 8*DeltaScint.Y() + 8*DeltaSteel.Y() + 7*DeltaAir.Y());
		                                               WorkingPosition.SetZ(MRDFacePosition.Z() + 8*DeltaScint.Z() + 8*DeltaSteel.Z() + 7*DeltaAir.Z());

		                                               if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter8Scint8Steel > m_p)) 
							       {
								       
							          nOutSide++;
                                                                  hEnergyOutSide->Fill(ProtonEnergy);
                                                                  hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                  hAngleOutSide->Fill(momentum.Theta()*180/PI);
							       
							       }

		                                               if ((EnergyAfter8Scint8Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
							       {
								       
							          nStopped++;
		           					  hEnergySNS->Fill(ProtonEnergy);
			                                          hMomentumSNS->Fill(momentum.Mag()*1000);
		           					  hAngleSNS->Fill(momentum.Theta()*180/PI);
		           					  hEnergyStopped->Fill(ProtonEnergy);
			                                          hMomentumStopped->Fill(momentum.Mag()*1000);
		         					  hAngleStopped->Fill(momentum.Theta()*180/PI);
								  hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
							       
							       }

		                                               if ((EnergyAfter8Scint8Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                       {

                                                                  hEnergyCheck8Scint8Steel->Fill(EnergyAfter8Scint8Steel);
			                                          hAngleCheck8Scint8Steel->Fill(momentum.Theta()*180/PI);

		                                                  MomMag = sqrt(EnergyAfter8Scint8Steel*EnergyAfter8Scint8Steel - m_p*m_p);

		                                                  double EnergyAfter9Scint8Steel = EnergyAfter8Scint8Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                                  WorkingPosition.SetX(MRDFacePosition.X() + 9*DeltaScint.X() + 8*DeltaSteel.X() + 7*DeltaAir.X());
		                                                  WorkingPosition.SetY(MRDFacePosition.Y() + 9*DeltaScint.Y() + 8*DeltaSteel.Y() + 7*DeltaAir.Y());
		                                                  WorkingPosition.SetZ(MRDFacePosition.Z() + 9*DeltaScint.Z() + 8*DeltaSteel.Z() + 7*DeltaAir.Z());

		                                                  if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter9Scint8Steel > m_p)) 
								  {
									  
								     nOutSide++;
                                                                     hEnergyOutSide->Fill(ProtonEnergy);
                                                                     hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                     hAngleOutSide->Fill(momentum.Theta()*180/PI);
								  
								  }

		                                                  if ((EnergyAfter9Scint8Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
								  {
									  
								     nStopped++;
		           					     hEnergySNS->Fill(ProtonEnergy);
			                                             hMomentumSNS->Fill(momentum.Mag()*1000);
		           					     hAngleSNS->Fill(momentum.Theta()*180/PI);
		           					     hEnergyStopped->Fill(ProtonEnergy);
			                                             hMomentumStopped->Fill(momentum.Mag()*1000);
		           					     hAngleStopped->Fill(momentum.Theta()*180/PI);
								     hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
								  
								  }

		                                                  if ((EnergyAfter9Scint8Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                          {

                                                                     hEnergyCheck9Scint8Steel->Fill(EnergyAfter9Scint8Steel);
			                                             hAngleCheck9Scint8Steel->Fill(momentum.Theta()*180/PI);

		                                                     MomMag = sqrt(EnergyAfter9Scint8Steel*EnergyAfter9Scint8Steel - m_p*m_p);

		                                                     double EnergyAfter9Scint9Steel = EnergyAfter9Scint8Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                                     WorkingPosition.SetX(MRDFacePosition.X() + 9*DeltaScint.X() + 9*DeltaSteel.X() + 8*DeltaAir.X());
		                                                     WorkingPosition.SetY(MRDFacePosition.Y() + 9*DeltaScint.Y() + 9*DeltaSteel.Y() + 8*DeltaAir.Y());
		                                                     WorkingPosition.SetZ(MRDFacePosition.Z() + 9*DeltaScint.Z() + 9*DeltaSteel.Z() + 8*DeltaAir.Z());

		                                                     if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter9Scint9Steel > m_p)) 
								     {
									     
								        nOutSide++;
                                                                        hEnergyOutSide->Fill(ProtonEnergy);
                                                                        hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                        hAngleOutSide->Fill(momentum.Theta()*180/PI);
								     
								     }

		                                                     if ((EnergyAfter9Scint9Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
								     {
									     
							  	        nStopped++;
		           						hEnergySNS->Fill(ProtonEnergy);
			                                                hMomentumSNS->Fill(momentum.Mag()*1000);
		           						hAngleSNS->Fill(momentum.Theta()*180/PI);
		           						hEnergyStopped->Fill(ProtonEnergy);
			                                                hMomentumStopped->Fill(momentum.Mag()*1000);
		           						hAngleStopped->Fill(momentum.Theta()*180/PI);
									hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
								     
								     }

		                                                     if ((EnergyAfter9Scint9Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                             {

                                                                        hEnergyCheck9Scint9Steel->Fill(EnergyAfter9Scint9Steel);
			                                                hAngleCheck9Scint9Steel->Fill(momentum.Theta()*180/PI);

		                                                        MomMag = sqrt(EnergyAfter9Scint9Steel*EnergyAfter9Scint9Steel - m_p*m_p);

		                                                        double EnergyAfter10Scint9Steel = EnergyAfter9Scint9Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                                        WorkingPosition.SetX(MRDFacePosition.X() + 10*DeltaScint.X() + 9*DeltaSteel.X() + 8*DeltaAir.X());
		                                                        WorkingPosition.SetY(MRDFacePosition.Y() + 10*DeltaScint.Y() + 9*DeltaSteel.Y() + 8*DeltaAir.Y());
		                                                        WorkingPosition.SetZ(MRDFacePosition.Z() + 10*DeltaScint.Z() + 9*DeltaSteel.Z() + 8*DeltaAir.Z());

		                                                        if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter10Scint9Steel > m_p)) 
									{
										
									   nOutSide++;
                                                                           hEnergyOutSide->Fill(ProtonEnergy);
                                                                           hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                           hAngleOutSide->Fill(momentum.Theta()*180/PI);
									
									}

		                                                        if ((EnergyAfter10Scint9Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
									{
										
									   nStopped++;
		           						   hEnergySNS->Fill(ProtonEnergy);
			                                                   hMomentumSNS->Fill(momentum.Mag()*1000);
		           						   hAngleSNS->Fill(momentum.Theta()*180/PI);
		           						   hEnergyStopped->Fill(ProtonEnergy);
			                                                   hMomentumStopped->Fill(momentum.Mag()*1000);
		           						   hAngleStopped->Fill(momentum.Theta()*180/PI);
									   hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
									
									}

		                                                        if ((EnergyAfter10Scint9Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                {

                                                                           hEnergyCheck10Scint9Steel->Fill(EnergyAfter10Scint9Steel);
			                                                   hAngleCheck10Scint9Steel->Fill(momentum.Theta()*180/PI);

		                                                           MomMag = sqrt(EnergyAfter10Scint9Steel*EnergyAfter10Scint9Steel - m_p*m_p);

		                                                           double EnergyAfter10Scint10Steel = EnergyAfter10Scint9Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                                           WorkingPosition.SetX(MRDFacePosition.X() + 10*DeltaScint.X() + 10*DeltaSteel.X() + 9*DeltaAir.X());
		                                                           WorkingPosition.SetY(MRDFacePosition.Y() + 10*DeltaScint.Y() + 10*DeltaSteel.Y() + 9*DeltaAir.Y());
		                                                           WorkingPosition.SetZ(MRDFacePosition.Z() + 10*DeltaScint.Z() + 10*DeltaSteel.Z() + 9*DeltaAir.Z());

		                                                           if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter10Scint10Steel > m_p)) 
									   {
										   
									      nOutSide++;
                                                                              hEnergyOutSide->Fill(ProtonEnergy);
                                                                              hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                              hAngleOutSide->Fill(momentum.Theta()*180/PI);
									   
									   }

		                                                           if ((EnergyAfter10Scint10Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
									   {
										   
									      nStopped++;
		           						      hEnergySNS->Fill(ProtonEnergy);
			                                                      hMomentumSNS->Fill(momentum.Mag()*1000);
		           						      hAngleSNS->Fill(momentum.Theta()*180/PI);
		           						      hEnergyStopped->Fill(ProtonEnergy);
			                                                      hMomentumStopped->Fill(momentum.Mag()*1000);
		           						      hAngleStopped->Fill(momentum.Theta()*180/PI);
									      hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
									   
									   }

		                                                           if ((EnergyAfter10Scint10Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                   {

                                                                              hEnergyCheck10Scint10Steel->Fill(EnergyAfter10Scint10Steel);
			                                                      hAngleCheck10Scint10Steel->Fill(momentum.Theta()*180/PI);

		                                                              MomMag = sqrt(EnergyAfter10Scint10Steel*EnergyAfter10Scint10Steel - m_p*m_p);

		                                                              double EnergyAfter11Scint10Steel = EnergyAfter10Scint10Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                                              WorkingPosition.SetX(MRDFacePosition.X() + 11*DeltaScint.X() + 10*DeltaSteel.X() + 9*DeltaAir.X());
		                                                              WorkingPosition.SetY(MRDFacePosition.Y() + 11*DeltaScint.Y() + 10*DeltaSteel.Y() + 9*DeltaAir.Y());
		                                                              WorkingPosition.SetZ(MRDFacePosition.Z() + 11*DeltaScint.Z() + 10*DeltaSteel.Z() + 9*DeltaAir.Z());

		                                                              if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter11Scint10Steel > m_p)) 
									      {
										      
									         nOutSide++;
                                                                                 hEnergyOutSide->Fill(ProtonEnergy);
                                                                                 hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                                 hAngleOutSide->Fill(momentum.Theta()*180/PI);
									      
									      }

		                                                              if ((EnergyAfter11Scint10Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
									      {
										      
									         nStopped++;
		           							 hEnergySNS->Fill(ProtonEnergy);
			                                                         hMomentumSNS->Fill(momentum.Mag()*1000);
		           							 hAngleSNS->Fill(momentum.Theta()*180/PI);
		           							 hEnergyStopped->Fill(ProtonEnergy);
			                                                         hMomentumStopped->Fill(momentum.Mag()*1000);
		           							 hAngleStopped->Fill(momentum.Theta()*180/PI);
										 hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
									      
									      }

		                                                              if ((EnergyAfter11Scint10Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                      {

                                                                                 hEnergyCheck11Scint10Steel->Fill(EnergyAfter11Scint10Steel);
			                                                         hAngleCheck11Scint10Steel->Fill(momentum.Theta()*180/PI);

		                                                                 MomMag = sqrt(EnergyAfter11Scint10Steel*EnergyAfter11Scint10Steel - m_p*m_p);

		                                                                 double EnergyAfter11Scint11Steel = EnergyAfter11Scint10Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                                                 WorkingPosition.SetX(MRDFacePosition.X() + 11*DeltaScint.X() + 11*DeltaSteel.X() + 10*DeltaAir.X());
		                                                                 WorkingPosition.SetY(MRDFacePosition.Y() + 11*DeltaScint.Y() + 11*DeltaSteel.Y() + 10*DeltaAir.Y());
		                                                                 WorkingPosition.SetZ(MRDFacePosition.Z() + 11*DeltaScint.Z() + 11*DeltaSteel.Z() + 10*DeltaAir.Z());

		                                                                 if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter11Scint11Steel > m_p)) 
										 {
											 
									 	    nOutSide++;
                                                                                    hEnergyOutSide->Fill(ProtonEnergy);
                                                                                    hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                                    hAngleOutSide->Fill(momentum.Theta()*180/PI);
										 
										 }

		                                                                 if ((EnergyAfter11Scint11Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
										 {
											 
										    nStopped++;
		           							    hEnergySNS->Fill(ProtonEnergy);
			                                                            hMomentumSNS->Fill(momentum.Mag()*1000);
		           							    hAngleSNS->Fill(momentum.Theta()*180/PI);
		           							    hEnergyStopped->Fill(ProtonEnergy);
			                                                            hMomentumStopped->Fill(momentum.Mag()*1000);
		           							    hAngleStopped->Fill(momentum.Theta()*180/PI);
										    hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
										 
										 }

		                                                                 if ((EnergyAfter11Scint11Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                         {

                                                                                    hEnergyCheck11Scint11Steel->Fill(EnergyAfter11Scint11Steel);
			                                                            hAngleCheck11Scint11Steel->Fill(momentum.Theta()*180/PI);

		                                                                    MomMag = sqrt(EnergyAfter11Scint11Steel*EnergyAfter11Scint11Steel - m_p*m_p);

		                                                                    double EnergyAfter12Scint11Steel = EnergyAfter11Scint11Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                                                    WorkingPosition.SetX(MRDFacePosition.X() + 12*DeltaScint.X() + 11*DeltaSteel.X() + 10*DeltaAir.X());
		                                                                    WorkingPosition.SetY(MRDFacePosition.Y() + 12*DeltaScint.Y() + 11*DeltaSteel.Y() + 10*DeltaAir.Y());
		                                                                    WorkingPosition.SetZ(MRDFacePosition.Z() + 12*DeltaScint.Z() + 11*DeltaSteel.Z() + 10*DeltaAir.Z());

		                                                                    if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter12Scint11Steel > m_p)) 
										    {
											    
										       nOutSide++;
                                                                                       hEnergyOutSide->Fill(ProtonEnergy);
                                                                                       hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                                       hAngleOutSide->Fill(momentum.Theta()*180/PI);
										    
										    }

		                                                                    if ((EnergyAfter12Scint11Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
										    {
											    
										       nStopped++;
		           							       hEnergySNS->Fill(ProtonEnergy);
			                                                               hMomentumSNS->Fill(momentum.Mag()*1000);
		           							       hAngleSNS->Fill(momentum.Theta()*180/PI);
		           							       hEnergyStopped->Fill(ProtonEnergy);
			                                                               hMomentumStopped->Fill(momentum.Mag()*1000);
		           							       hAngleStopped->Fill(momentum.Theta()*180/PI);
										       hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
										    
										    }

		                                                                    if ((EnergyAfter12Scint11Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                            {

                                                                                       hEnergyCheck12Scint11Steel->Fill(EnergyAfter12Scint11Steel);
			                                                               hAngleCheck12Scint11Steel->Fill(momentum.Theta()*180/PI);

		                                                                       MomMag = sqrt(EnergyAfter12Scint11Steel*EnergyAfter12Scint11Steel - m_p*m_p);

		                                                                       double EnergyAfter12Scint12Steel = EnergyAfter12Scint11Steel - MPVSteel(MomMag)*100*rangeSteel;

		                                                                       WorkingPosition.SetX(MRDFacePosition.X() + 12*DeltaScint.X() + 12*DeltaSteel.X() + 11*DeltaAir.X());
		                                                                       WorkingPosition.SetY(MRDFacePosition.Y() + 12*DeltaScint.Y() + 12*DeltaSteel.Y() + 11*DeltaAir.Y());
		                                                                       WorkingPosition.SetZ(MRDFacePosition.Z() + 12*DeltaScint.Z() + 12*DeltaSteel.Z() + 11*DeltaAir.Z());

		                                                                       if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter12Scint12Steel > m_p)) 
										       {
											       
										          nOutSide++;
                                                                                          hEnergyOutSide->Fill(ProtonEnergy);
                                                                                          hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                                          hAngleOutSide->Fill(momentum.Theta()*180/PI);
										       
										       }

		                                                                       if ((EnergyAfter12Scint12Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
										       {
											       
										          nStopped++;
		           								  hEnergySNS->Fill(ProtonEnergy);
			                                                                  hMomentumSNS->Fill(momentum.Mag()*1000);
		           								  hAngleSNS->Fill(momentum.Theta()*180/PI);
		           								  hEnergyStopped->Fill(ProtonEnergy);
			                                                                  hMomentumStopped->Fill(momentum.Mag()*1000);
		           								  hAngleStopped->Fill(momentum.Theta()*180/PI);
											  hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
										       
										       }

		                                                                       if ((EnergyAfter12Scint12Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                               {

                                                                                          hEnergyCheck12Scint12Steel->Fill(EnergyAfter12Scint12Steel);
			                                                                  hAngleCheck12Scint12Steel->Fill(momentum.Theta()*180/PI);

		                                                                          MomMag = sqrt(EnergyAfter12Scint12Steel*EnergyAfter12Scint12Steel - m_p*m_p);

		                                                                          double EnergyAfter13Scint12Steel = EnergyAfter12Scint12Steel - MPVCarbon(MomMag)*100*rangeScint;// - MPVSteel(MomMag)*100*rangeSteel;

		                                                                          WorkingPosition.SetX(MRDFacePosition.X() + 13*DeltaScint.X() + 12*DeltaSteel.X() + 11*DeltaAir.X());
		                                                                          WorkingPosition.SetY(MRDFacePosition.Y() + 13*DeltaScint.Y() + 12*DeltaSteel.Y() + 11*DeltaAir.Y());
		                                                                          WorkingPosition.SetZ(MRDFacePosition.Z() + 13*DeltaScint.Z() + 12*DeltaSteel.Z() + 11*DeltaAir.Z());

		                                                                          if (((WorkingPosition.X() > MRDx_f) || (WorkingPosition.X() < MRDx_0) || (WorkingPosition.Y() > MRDy_f) || (WorkingPosition.Y() < MRDy_0)) && (EnergyAfter13Scint12Steel > m_p)) 
											  {
												  
											     nOutSide++;
                                                                                             hEnergyOutSide->Fill(ProtonEnergy);
                                                                                             hMomentumOutSide->Fill(momentum.Mag()*1000);
                                                                                             hAngleOutSide->Fill(momentum.Theta()*180/PI);
											  
											  }

		                                                                          if ((EnergyAfter13Scint12Steel <= m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0)) 
											  {
												  
											     nStopped++;
		           								     hEnergySNS->Fill(ProtonEnergy);
			                                                                     hMomentumSNS->Fill(momentum.Mag()*1000);
		           								     hAngleSNS->Fill(momentum.Theta()*180/PI);
		           								     hEnergyStopped->Fill(ProtonEnergy);
			                                                                     hMomentumStopped->Fill(momentum.Mag()*1000);
		           								     hAngleStopped->Fill(momentum.Theta()*180/PI);
											     hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);
											  
											  }

		                                                                          if ((EnergyAfter13Scint12Steel > m_p) && (MRDx_f > WorkingPosition.X() > MRDx_0) && (MRDy_f > WorkingPosition.Y() > MRDy_0))
			                                                                  {

											     nNotStopped++;
                                                                                             hEnergyCheck13Scint12Steel->Fill(EnergyAfter13Scint12Steel);
			                                                                     hAngleCheck13Scint12Steel->Fill(momentum.Theta()*180/PI);
											     hEnergySNS->Fill(ProtonEnergy);
			                                                                     hMomentumSNS->Fill(momentum.Mag()*1000);
											     hAngleSNS->Fill(momentum.Theta()*180/PI);
											     hEnergyNotStopped->Fill(ProtonEnergy);
			                                                                     hMomentumNotStopped->Fill(momentum.Mag()*1000);
											     hAngleNotStopped->Fill(momentum.Theta()*180/PI);
											     hSNSProton2D->Fill(momentum.Theta()*180/PI, momentum.Mag()*1000);

			                                                                  } //<---Close if statement for nonzero energy after 13 Scint 12 Steel


			                                                               } //<---Close if statement for nonzero energy after 12 Scint 12 Steel


			                                                            } //<---Close if statement for nonzero energy after 12 Scint 11 Steel


			                                                         } //<---Close if statement for nonzero energy after 11 Scint 11 Steel


			                                                      } //<---Close if statement for nonzero energy after 11 Scint 10 Steel


			                                                   } //<---Close if statement for nonzero energy after 10 Scint 10 Steel


			                                                } //<---Close if statement for nonzero energy after 10 Scint 9 Steel


			                                             } //<---Close if statement for nonzero energy after 9 Scint 9 Steel


			                                          } //<---Close if statement for nonzero energy after 9 Scint 8 Steel


			                                       } //<---Close if statement for nonzero energy after 8 Scint 8 Steel


			                                    } //<---Close if statement for nonzero energy after 8 Scint 7 Steel


			                                 } //<---Close if statement for nonzero energy after 7 Scint 7 Steel


			                              } //<---Close if statement for nonzero energy after 7 Scint 6 Steel


			                           } //<---Close if statement for nonzero energy after 6 Scint 6 Steel


			                        } //<---Close if statement for nonzero energy after 6 Scint 5 Steel


			                     } //<---Close if statement for nonzero energy after 5 Scint 5 Steel


			                  } //<---Close if statement for nonzero energy after 5 Scint 4 Steel


			               } //<---Close if statement for nonzero energy after 4 Scint 4 Steel


			            } //<---Close if statement for nonzero energy after 4 Scint 3 Steel


			         } //<---Close if statement for nonzero energy after 3 Scint 3 Steel


			      } //<---Close if statement for nonzero energy after 3 Scint 2 Steel


			   } //<---Close if statement for nonzero energy after 2 Scint 2 Steel


			} //<---Close if statement for nonzero energy after 2 Scint 1 Steel


		     } //<--- Close if statement for nonzero energy after 1 Scint 1 Steel


		  } //<--- Close if statement for nonzero energy after 1 Scint 0 Steel


	       } //<--- Close if statement for nonzero energy after EC


	    } //<--- Close if statement for nonzero energy after scibar
	 

	 } //<--- Close if statement for making it to the front face of the MRD


	 if ((XposMRDBack >= MRDx_0) && (XposMRDBack <= MRDx_f) && (YposMRDBack >= MRDy_0) && (YposMRDBack <= MRDy_f)) 
	 {
		 
            nMRDBack++;
	 
	 } //<--- Close if statement for making it out the back of the MRD


      } //<--- Close if statement for events with protons


      nProtons = 0;

   } //<--- Close jentry for loop


   std::cout<<"Number of Events with at least a single proton in final state = "<<nEventsWithProton<<std::endl;
   std::cout<<"Number of Protons that are pointed at the MRD = "<<nMRDFace<<std::endl;
   std::cout<<"Number of Protons that could go out the back of the MRD = "<<nMRDBack<<std::endl;
   std::cout<<"|------------------------------------------------------------------|"<<std::endl;
   std::cout<<"Number of Protons that exit SciBar with nonzero energy = "<<nOutSciBar<<std::endl;
   std::cout<<"Number of Protons that exit EC with nonzero energy = "<<nOutEC<<std::endl;
   std::cout<<"|------------------------------------------------------------------|"<<std::endl;
   std::cout<<"Number that made it to the MRD = "<<nMadeMRD<<std::endl;
   std::cout<<"|------------------------------------------------------------------|"<<std::endl;
   std::cout<<"Number that stopped in the MRD = "<<nStopped<<std::endl;
   std::cout<<"Number that did not stop in the MRD = "<<nNotStopped<<std::endl;
   std::cout<<"Number that exited the side of the MRD = "<<nOutSide<<std::endl;


   //---------------------------------|
   //--- Saving Histograms to File ---|
   //---------------------------------|
   TFile *TProtonInfo = new TFile("../ROOTFILES/AprotonRS.root", "RECREATE");

   hTotalProton2D->Write("Total2D");
   hTotalProtonEnergy->Write("TotalE");
   hTotalProtonMomentum->Write("TotalM");
   hTotalProtonAngle->Write("TotalA");

   hSNSProton2D->Write("SNS2D");
   hEnergySNS->Write("SNSE");
   hMomentumSNS->Write("SNSM");
   hAngleSNS->Write("SNSA");

   hEnergyTMMRD->Write("TMMRDE");
   hMomentumTMMRD->Write("TMMRDM");
   hAngleTMMRD->Write("TMMRDA");

   hEnergyStopped->Write("StoppedE");
   hMomentumStopped->Write("StoppedM");
   hAngleStopped->Write("StoppedA");

   hEnergyNotStopped->Write("NotStoppedE");
   hMomentumNotStopped->Write("NotStoppedM");
   hAngleNotStopped->Write("NotStoppedA");

   hEnergyOutSide->Write("OutSideE");
   hMomentumOutSide->Write("OutSideM");
   hAngleOutSide->Write("OutSideA");

   TProtonInfo->Write();
   TProtonInfo->Close();
   //---------------------------------|

} //<--- Close void loop
//===========================================|
