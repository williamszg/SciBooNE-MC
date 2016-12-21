{
// ####################
// # Read in the Data #
// ####################

// =======================================================================================
//                ### Berger Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewBS = (TH1D*)f1->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewBS = (TH1D*)f1->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewBS = (TH1D*)f1->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewBS = (TH1D*)f1->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle


hTotalPNewBS->Sumw2();
hTotalGoodPNewBS->Sumw2();
hTotalCosNewBS->Sumw2();
hTotalGoodCosNewBS->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPBS = new TH1D("RatioPBS", "Efficiencies for Momentums", 40, 0, 2000);

// ### Formatting the plot ###
RatioPBS->SetLineColor(kRed);
RatioPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBS->GetXaxis()->CenterTitle();
RatioPBS->GetYaxis()->SetTitle("Efficiency");
RatioPBS->GetYaxis()->CenterTitle();

RatioPBS->Divide(hTotalGoodPNewBS, hTotalPNewBS);


// =======================================================================================
//                ### Ryan Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================

TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRSBar.root"); //Load Total Muon Info File

TH1D *hTotalPNewRS = (TH1D*)f2->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRS = (TH1D*)f2->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRS = (TH1D*)f2->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRS = (TH1D*)f2->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

hTotalPNewRS->Sumw2();
hTotalGoodPNewRS->Sumw2();
hTotalCosNewRS->Sumw2();
hTotalGoodCosNewRS->Sumw2();



TH1D *RatioPRS = new TH1D("RatioPRS", "Efficiencies for Momentums", 40, 0, 2000);


// ### Formatting the plot ###
RatioPRS->SetLineColor(kBlue);
RatioPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRS->GetXaxis()->CenterTitle();
RatioPRS->GetYaxis()->SetTitle("Efficiency");
RatioPRS->GetYaxis()->CenterTitle();


RatioPRS->Divide(hTotalGoodPNewRS, hTotalPNewRS);





// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPRS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("SciBooNE MC");
leg->AddEntry(RatioPRS,"R-S Model");
leg->AddEntry(RatioPBS,"B-S Model"); 
leg->Draw();



// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c2 = new TCanvas("c2", "Muon Momentums ");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalPNewRS->Scale(1/hTotalPNewRS->Integral());

hTotalPNewBS->Scale(1/hTotalPNewBS->Integral());

hTotalPNewRS->SetLineColor(kBlue);
hTotalPNewRS->SetLineWidth(2);

hTotalPNewBS->SetLineColor(kRed);
hTotalPNewBS->SetLineWidth(2);


hTotalPNewBS->Draw("histo");
hTotalPNewRS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hTotalPNewRS,"R-S Model");
leg1->AddEntry(hTotalPNewBS,"B-S Model"); 
leg1->Draw();


}
