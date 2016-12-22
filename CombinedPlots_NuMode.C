{
// ####################
// # Read in the Data #
// ####################

// =======================================================================================
//                     ### Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f1 = new TFile("./ROOTFILES/totalmuoninfoBS.root"); //Load Total Muon Info File

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
TH1D *RatioCBS = new TH1D("RatioCBS", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPBS->SetLineColor(kRed);
RatioPBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPBS->GetXaxis()->CenterTitle();
RatioPBS->GetYaxis()->SetTitle("Efficiency");
RatioPBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCBS->SetLineColor(kRed);
RatioCBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCBS->GetXaxis()->CenterTitle();
RatioCBS->GetYaxis()->SetTitle("Efficiency");
RatioCBS->GetYaxis()->CenterTitle();


RatioPBS->Divide(hTotalGoodPNewBS, hTotalPNewBS);
RatioCBS->Divide(hTotalGoodCosNewBS, hTotalCosNewBS);




// =======================================================================================
//                ### Rein Sehgal Files for Anti-Neutrino Mode ###
// =======================================================================================


TFile *f2 = new TFile("./ROOTFILES/totalmuoninfoRS.root"); //Load Total Muon Info File

TH1D *hTotalPNewRS = (TH1D*)f2->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewRS = (TH1D*)f2->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewRS = (TH1D*)f2->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewRS = (TH1D*)f2->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

hTotalPNewRS->Sumw2();
hTotalGoodPNewRS->Sumw2();
hTotalCosNewRS->Sumw2();
hTotalGoodCosNewRS->Sumw2();


// ### Defining the ratio histogram ###
TH1D *RatioPRS = new TH1D("RatioPRS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCRS = new TH1D("RatioCRS", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPRS->SetLineColor(kBlue);
RatioPRS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPRS->GetXaxis()->CenterTitle();
RatioPRS->GetYaxis()->SetTitle("Efficiency");
RatioPRS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCRS->SetLineColor(kBlue);
RatioCRS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCRS->GetXaxis()->CenterTitle();
RatioCRS->GetYaxis()->SetTitle("Efficiency");
RatioCRS->GetYaxis()->CenterTitle();


RatioPRS->Divide(hTotalGoodPNewRS, hTotalPNewRS);
RatioCRS->Divide(hTotalGoodCosNewRS, hTotalCosNewRS);




// =======================================================================================
//                  ### Old Berger Sehgal Files for Neutrino Mode ###
// =======================================================================================


TFile *f3 = new TFile("./ROOTFILES/totalmuoninfoOBS.root"); //Load Total Muon Info File

TH1D *hTotalPNewOBS = (TH1D*)f3->Get("TMuonMom_1"); //Make a clone of the h5 histogram from the NeutrinoMode.C file for total muon momentum
TH1D *hTotalGoodPNewOBS = (TH1D*)f3->Get("TGMuonMom_1"); //Make a clone of the h11 histogram from the NeutrinoMode.C file for total good muon momentum

TH1D *hTotalCosNewOBS = (TH1D*)f3->Get("TMuonCos_1"); //Make a clone of the h7 histogram from the NeutrinoMode.C file for total muon angle
TH1D *hTotalGoodCosNewOBS = (TH1D*)f3->Get("TGMuonCos_1"); //Make a clone of the h12 histogram from the NeutrinoMode.C file for total good muon angle

hTotalPNewOBS->Sumw2();
hTotalGoodPNewOBS->Sumw2();
hTotalCosNewOBS->Sumw2();
hTotalGoodCosNewOBS->Sumw2();

// ### Defining the ratio histogram ###
TH1D *RatioPOBS = new TH1D("RatioPOBS", "Efficiencies for Momentums", 40, 0, 2000);
TH1D *RatioCOBS = new TH1D("RatioCOBS", "Efficiencies for Angles", 40, 0, 180);

// ### Formatting the plot ###
RatioPOBS->SetLineColor(kGreen);
RatioPOBS->GetXaxis()->SetTitle("Muon Momentum Magnitude (MeV)");
RatioPOBS->GetXaxis()->CenterTitle();
RatioPOBS->GetYaxis()->SetTitle("Efficiency");
RatioPOBS->GetYaxis()->CenterTitle();

// ### Formatting the plot ###
RatioCOBS->SetLineColor(kGreen);
RatioCOBS->GetXaxis()->SetTitle("Muon Angle (Degrees)");
RatioCOBS->GetXaxis()->CenterTitle();
RatioCOBS->GetYaxis()->SetTitle("Efficiency");
RatioCOBS->GetYaxis()->CenterTitle();


RatioPOBS->Divide(hTotalGoodPNewOBS, hTotalPNewOBS);
RatioCOBS->Divide(hTotalGoodCosNewOBS, hTotalCosNewOBS);




// ##############################################
// # Drawing the Momentum Efficiency Histograms #
// ##############################################

TCanvas *c1 = new TCanvas("c1", "Muon Momentums Efficiencies Histogram");
c1->SetTicks();
c1->SetFillColor(kWhite);

RatioPBS->Draw("E1");
RatioPRS->Draw("E1same");
RatioPOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("SciBooNE MC");
leg->AddEntry(RatioPRS,"New R-S Model");
leg->AddEntry(RatioPBS,"New B-S Model");
leg->AddEntry(RatioPOBS, "Old B-S Model");
leg->Draw();




// ############################################
// # Drawing the Angles Efficiency Histograms #
// ############################################

TCanvas *c6 = new TCanvas("c6", "Muon Angles Efficiencies Histogram");
c6->SetTicks();
c6->SetFillColor(kWhite);

RatioCBS->Draw("E1");
RatioCRS->Draw("E1same");
RatioCOBS->Draw("E1same");

// ### Defining the legend for the plot ###
TLegend *leg5 = new TLegend();
leg5 = new TLegend(0.58,0.65,0.88,0.88);
leg5->SetTextSize(0.04);
leg5->SetTextAlign(12);
leg5->SetFillColor(kWhite);
leg5->SetLineColor(kWhite);
leg5->SetShadowColor(kWhite);
leg5->SetHeader("SciBooNE MC");
leg5->AddEntry(RatioCRS,"New R-S Model");
leg5->AddEntry(RatioCBS,"New B-S Model");
leg5->AddEntry(RatioCOBS, "Old B-S Model");
leg5->Draw();




// ###################################
// # Drawing the Momentum Histograms #
// ###################################

TCanvas *c2 = new TCanvas("c2", "Muon Momentums");
c2->SetTicks();
c2->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalPNewRS->Scale(1/hTotalPNewRS->Integral());

hTotalPNewBS->Scale(1/hTotalPNewBS->Integral());

hTotalPNewOBS->Scale(1/hTotalPNewOBS->Integral());

hTotalPNewRS->SetLineColor(kBlue);
hTotalPNewRS->SetLineWidth(2);

hTotalPNewBS->SetLineColor(kRed);
hTotalPNewBS->SetLineWidth(2);

hTotalPNewOBS->SetLineColor(kGreen);
hTotalPNewOBS->SetLineWidth(2);

hTotalPNewOBS->Draw("histo");
hTotalPNewRS->Draw("histosame");
hTotalPNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg1 = new TLegend();
leg1 = new TLegend(0.58,0.65,0.88,0.88);
leg1->SetTextSize(0.04);
leg1->SetTextAlign(12);
leg1->SetFillColor(kWhite);
leg1->SetLineColor(kWhite);
leg1->SetShadowColor(kWhite);
leg1->SetHeader("SciBooNE MC");
leg1->AddEntry(hTotalPNewRS,"New R-S Model");
leg1->AddEntry(hTotalPNewBS,"New B-S Model");
leg1->AddEntry(hTotalPNewOBS,"Old B-S Model");
leg1->Draw();




// #################################
// # Drawing the Cosine Histograms #
// #################################

TCanvas *c3 = new TCanvas("c3", "Muon Angles");
c3->SetTicks();
c3->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalCosNewRS->Scale(1/hTotalCosNewRS->Integral());

hTotalCosNewBS->Scale(1/hTotalCosNewBS->Integral());

hTotalCosNewOBS->Scale(1/hTotalCosNewOBS->Integral());

hTotalCosNewRS->SetLineColor(kBlue);
hTotalCosNewRS->SetLineWidth(2);

hTotalCosNewBS->SetLineColor(kRed);
hTotalCosNewBS->SetLineWidth(2);

hTotalCosNewOBS->SetLineColor(kGreen);
hTotalCosNewOBS->SetLineWidth(2);

hTotalCosNewBS->Draw("histo");
hTotalCosNewRS->Draw("histosame");
hTotalCosNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg2 = new TLegend();
leg2 = new TLegend(0.58,0.65,0.88,0.88);
leg2->SetTextSize(0.04);
leg2->SetTextAlign(12);
leg2->SetFillColor(kWhite);
leg2->SetLineColor(kWhite);
leg2->SetShadowColor(kWhite);
leg2->SetHeader("SciBooNE MC");
leg2->AddEntry(hTotalCosNewRS,"New R-S Model");
leg2->AddEntry(hTotalCosNewBS,"New B-S Model");
leg2->AddEntry(hTotalCosNewOBS, "Old B-S Model");
leg2->Draw();




// ########################################
// # Drawing the Good Momentum Histograms #
// ########################################

TCanvas *c4 = new TCanvas("c4", "Good Muon Momentums");
c4->SetTicks();
c4->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodPNewRS->Scale(1/hTotalGoodPNewRS->Integral());

hTotalGoodPNewBS->Scale(1/hTotalGoodPNewBS->Integral());

hTotalGoodPNewOBS->Scale(1/hTotalGoodPNewOBS->Integral());

hTotalGoodPNewRS->SetLineColor(kBlue);
hTotalGoodPNewRS->SetLineWidth(2);

hTotalGoodPNewBS->SetLineColor(kRed);
hTotalGoodPNewBS->SetLineWidth(2);

hTotalGoodPNewOBS->SetLineColor(kGreen);
hTotalGoodPNewOBS->SetLineWidth(2);

hTotalGoodPNewBS->Draw("histo");
hTotalGoodPNewRS->Draw("histosame");
hTotalGoodPNewOBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg3 = new TLegend();
leg3 = new TLegend(0.58,0.65,0.88,0.88);
leg3->SetTextSize(0.04);
leg3->SetTextAlign(12);
leg3->SetFillColor(kWhite);
leg3->SetLineColor(kWhite);
leg3->SetShadowColor(kWhite);
leg3->SetHeader("SciBooNE MC");
leg3->AddEntry(hTotalGoodPNewRS,"New R-S Model");
leg3->AddEntry(hTotalGoodPNewBS,"New B-S Model");
leg3->AddEntry(hTotalGoodPNewOBS, "Old B-S Model");
leg3->Draw();




// ######################################
// # Drawing the Good Cosine Histograms #
// ######################################

TCanvas *c5 = new TCanvas("c5", "Good Muon Angles");
c5->SetTicks();
c5->SetFillColor(kWhite);

// Area normalzing the plot 
hTotalGoodCosNewRS->Scale(1/hTotalGoodCosNewRS->Integral());

hTotalGoodCosNewBS->Scale(1/hTotalGoodCosNewBS->Integral());

hTotalGoodCosNewOBS->Scale(1/hTotalGoodCosNewOBS->Integral());

hTotalGoodCosNewRS->SetLineColor(kBlue);
hTotalGoodCosNewRS->SetLineWidth(2);

hTotalGoodCosNewBS->SetLineColor(kRed);
hTotalGoodCosNewBS->SetLineWidth(2);

hTotalGoodCosNewOBS->SetLineColor(kGreen);
hTotalGoodCosNewOBS->SetLineWidth(2);

hTotalGoodCosNewOBS->Draw("histo");
hTotalGoodCosNewRS->Draw("histosame");
hTotalGoodCosNewBS->Draw("histosame");


// ### Defining the legend for the plot ###
TLegend *leg4 = new TLegend();
leg4 = new TLegend(0.58,0.65,0.88,0.88);
leg4->SetTextSize(0.04);
leg4->SetTextAlign(12);
leg4->SetFillColor(kWhite);
leg4->SetLineColor(kWhite);
leg4->SetShadowColor(kWhite);
leg4->SetHeader("SciBooNE MC");
leg4->AddEntry(hTotalGoodCosNewRS,"New R-S Model");
leg4->AddEntry(hTotalGoodCosNewBS,"New B-S Model");
leg4->AddEntry(hTotalGoodCosNewOBS, "Old B-S Model");
leg4->Draw();




}
