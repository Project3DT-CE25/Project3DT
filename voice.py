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
spk.Speak("อุณหภูมิเกิน 37.5องศา กรุณาลองใหม่อีกครั้ง")
spk.Speak("กรุณาลองใหม่อีกครั้ง")
spk.Speak("ผ่านครับ")
import pyttsx3
engine = pyttsx3.init()
TH_voice_id = "HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Speech\Voices\Tokens\MSTTS_V110_thTH_Pattara"
engine.setProperty('volume', 1)  # Volume 0-1
engine.setProperty('rate', 180)  #148
engine.setProperty('voice', TH_voice_id)
engine.say('กรุณาสวมหน้ากากอนามัยด้วยครับ')
engine.runAndWait()
