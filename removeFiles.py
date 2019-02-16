#this removes obj and exe file generated by vcvarsall x64 // cl commands just to clean the repo while pushing into github

#general imports
import os
import sys
import re

#check arguments passed
if len (sys.argv) < 2 :
    print("Usage: python removeFiles.py folderpath filestype1 filetype2 \n example python removeFiles.py spoj/cpp .obj .exe .java")
    sys.exit(1)

#set path
root_path = sys.argv[1]

#get total list of files available in directory

listofTotalFiles=os.listdir(root_path)
print("All the Available files in directory:\n "+ str(listofTotalFiles))

#filter only the files to be removed

#create regex
regex="" + sys.argv[2]
for i in range(3,len(sys.argv)):
       regex += ("|" + sys.argv[i]) 
print("regex=" + regex)

#get the removing files list

fileTypeRegex = re.compile(regex)
removingList = list(filter(fileTypeRegex.search, listofTotalFiles)) # Read Note
print("the following list of files will be removed =" + str(removingList))

#remove the files

for File in removingList:
    try:
        os.remove(os.path.join(root_path,str(File)))
        print("file removed: " + str(File))
    except OSError as e:  ## if failed, report it back to the user ##
        print ("Error: %s - %s." % (e.filename, e.strerror))
