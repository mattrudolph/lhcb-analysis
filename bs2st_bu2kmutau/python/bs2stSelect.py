#!/usr/bin/env python

from ROOT import gROOT, TCanvas, TFile, TDirectory, TH1F, kBlue, kRed
gROOT.Macro("~/root/rootlogon.C")
f = TFile("test_jpsi.root")

c = TCanvas()


dsig = f.Get("Signal/Bs2stSelect_Sig")

dbkg_in_sig = f.Get("SameSignBG/Bs2stSelect_Sig")

dbkg = f.Get("SameSignBG/Bs2stSelect_Bkg")

for hkey in dsig.GetListOfKeys():

    hsig = hkey.ReadObj()
    hbkg_in_sig = dbkg_in_sig.Get(hkey.GetName())
    hbkg = dbkg.Get(hkey.GetName())

    hsig.Add( hbkg_in_sig, -1)
    
    hsig.Scale(1./hsig.Integral() )
    
    hbkg.Scale(1./hbkg.Integral() )

    hsig.SetLineColor(kBlue)
    hsig.SetMarkerColor(kBlue)

    hbkg.SetLineColor(kRed)
    hbkg.SetMarkerColor(kRed)
    

    hbkg.Draw()
    hsig.Draw("SAME")

    c.SaveAs("plots/"+hsig.GetName()+".png")


#special plot for right/wrong b energy
dsig_right = f.Get("Signal/Bs2stSelect_Sig_Right")
dsig_wrong = f.Get("Signal/Bs2stSelect_Sig_Wrong")

hists = ["h_b_e", "h_bs2st_e", "h_m_e","h_b_pt","h_bs2st_pt"]
for h in hists:
    hsig_right = dsig_right.Get(h)
    hsig_wrong = dsig_wrong.Get(h)

    hbkg_in_sig = dbkg_in_sig.Get(h)
    hbkg = dbkg.Get(h)
    
    hsig_right.Add( hbkg_in_sig, -0.5)
    hsig_wrong.Add( hbkg_in_sig, -0.5)

    hsig_right.Scale(0.5/hsig_right.Integral())
    hsig_wrong.Scale(0.5/hsig_wrong.Integral())

    hbkg.Scale(1./hbkg.Integral())
    
    hsig_right.SetLineColor(kBlue)
    hsig_right.SetMarkerColor(kBlue)
    
    hbkg.SetLineColor(kRed)
    hbkg.SetMarkerColor(kRed)

    hbkg.Draw()
    hsig_right.Draw("SAME")
    hsig_wrong.Draw("SAME")

    c.SaveAs("plots/" + h + "_rightwrong.png")
