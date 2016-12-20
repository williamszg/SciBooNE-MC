{

// ####################
// # Read in the Data #
// ####################

TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBSBar.root"); //Load Total Muon Info File


//------------------------------------------------------------------------------
//                           Efficiency Plots
//------------------------------------------------------------------------------

TH1D *RatioP = new TH1D("RatioP", "Efficiencies for Momentums", 40, 0, 2000); //This is the histogram for the muon momentum ratios
TH1D *RatioC = new TH1D("RatioC", "Efficiencies for Angles", 40, 0, 180); //This is the histogram for the muon angles ratios

TH1D *hTP = (TH1D*)f1->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTGP = (TH1D*)f1->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTC = (TH1D*)f1->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTGC = (TH1D*)f1->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

hTP->Sumw2();
hTGP->Sumw2();
hTC->Sumw2();
hTGC->Sumw2();

RatioP->Divide(hTGP, hTP); //Fill the RatioP histogram with the hGP histogram divided by the hTP histogram
RatioC->Divide(hTGC, hTC); //Fill the RatioC histogram with the hGC histogram divided by the hTC histogram


// ################################
// # Drawing the Ratio Histograms #
// ################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);
RatioP->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioP->GetXaxis()->CenterTitle();
RatioP->GetYaxis()->SetTitle("Efficiency");
RatioP->GetYaxis()->CenterTitle();
RatioP->Draw("E1");

TCanvas *c2 = new TCanvas("c2", "Muon Angles Efficiencies Histogram");
c2->SetTicks();
c2->SetFillColor(kWhite);
RatioC->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioC->GetXaxis()->CenterTitle();
RatioC->GetYaxis()->SetTitle("Efficiency");
RatioC->GetYaxis()->CenterTitle();
RatioC->Draw("E1");


} //End file

