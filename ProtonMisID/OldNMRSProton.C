#define OldNMRSProton_cxx
#include "OldNMRSProton.h"
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
TH1D *hTotalProtonAngle = new TH1D("hTotalProtonAngle", "The Angles of all of the Proton Events", 60, 0, 180);

TH1D *hProtonEnergyAfterSciBar = new TH1D("hProtonEnergyAfterSciBar", "The Energies of the Protons After Traversing SciBar", 50, 0, 2500);
TH1D *hProtonAngleAfterSciBar = new TH1D("hProtonAngleAfterSciBar", "The Angles of the Protons After Traversing SciBar", 60, 0, 180);

TH1D *hProtonEnergyAfterEC = new TH1D("hProtonEnergyAfterEC", "The Energies of the Protons After Traversing the EC", 50, 0, 2500);
TH1D *hProtonAngleAfterEC = new TH1D("hProtonAngleAfterEC", "The Angles of the Protons After Traversing the EC", 60, 0, 180);

TH1D *hEnergyCheck = new TH1D("hEnergyCheck", "Checking the Energy After 1 Scint Layer and 0 Steel Layers of the MRD", 50, 0, 2500);
TH1D *hAngleCheck = new TH1D("hAngleCheck", "Checking the Angle After 1 Scint Layer and 0 Steel Layers of the MRD", 60, 0, 180);
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
void OldNMRSProton::Loop()
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


      if (nProtons > 0 && StdHepP4[ProtonRegister][2] > 0) 
      {

         nEventsWithProton++;

	 TVector3 momentum(StdHepP4[ProtonRegister][0],StdHepP4[ProtonRegister][1],StdHepP4[ProtonRegister][2]); //Initial Proton Momentum
	 TVector3 direction(momentum.X()/momentum.Mag(),momentum.Y()/momentum.Mag(),momentum.Z()/momentum.Mag()); //Unit vector of Proton Momentum (direction Proton is going)
	 TVector3 position(Xpos,Ypos,Zpos); //Initial Proton Position

         hTotalProtonEnergy->Fill(StdHepP4[ProtonRegister][3]*1000);
	 hTotalProtonAngle->Fill(momentum.Theta()*180/PI);
         
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

	    if (EnergyAfterSciBar > 0) 
	    {

	       hProtonEnergyAfterSciBar->Fill(EnergyAfterSciBar);
	       hProtonAngleAfterSciBar->Fill(momentum.Theta()*180/PI);
	       nOutSciBar++;

	       double EnergyAfterEC = EnergyAfterSciBar - dEnergyLossECdTheta*cos(momentum.Theta());
	       if (EnergyAfterEC > 0)
	       {

                  hProtonEnergyAfterEC->Fill(EnergyAfterEC);
		  hProtonAngleAfterEC->Fill(momentum.Theta()*180/PI);
		  nOutEC++;

		  double MomMag = sqrt(EnergyAfterEC*EnergyAfterEC - m_p*m_p);
		  TVector3 ProtonMomentum(MomMag*direction.X(),MomMag*direction.Y(),MomMag*direction.Z());
		  TVector3 MRDFacePosition(XposMRDFace,YposMRDFace,SBz_f+DownstreamMRDFace);

		  double rangeScint = ScintThickness/cos(momentum.Theta());
		  double rangeSteel = SteelThickness/cos(momentum.Theta());
		  double rangeAir = AirThickness/cos(momentum.Theta());

		  TVector3 DeltaScint(rangeScint*direction.X(),rangeScint*direction.Y(),rangeScint*direction.Z());
		  TVector3 DeltaSteel(rangeSteel*direction.X(),rangeSteel*direction.Y(),rangeSteel*direction.Z());
		  TVector3 DeltaAir(rangeAir*direction.X(),rangeAir*direction.Y(),rangeAir*direction.Z());

		  double EnergyAfter1Scint0Steel = EnergyAfterEC - MPVCarbon(ProtonMomentum.Mag())*100*rangeScint;
		  if (EnergyAfter1Scint0Steel>0) 
		  {

                     hEnergyCheck->Fill(EnergyAfter1Scint0Steel);
		     hAngleCheck->Fill(momentum.Theta()*180/PI);

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

} //<--- Close void loop
//===========================================|
