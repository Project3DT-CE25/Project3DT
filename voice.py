import win32com.client as wincl
TH_voice_id = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech_OneCore\Voices\Tokens\MSTTS_V110_thTH_Pattara"
speaker_number = 1
spk = wincl.Dispatch("SAPI.SpVoice")
vcs = spk.GetVoices()
SVSFlag = 11
print(vcs.Item (speaker_number) .GetAttribute ("Name")) # speaker name
spk.Voice
spk.SetVoice(vcs.Item(speaker_number)) # set voice (see Windows Text-to-Speech settings)
spk.Speak("35.5องศา")

