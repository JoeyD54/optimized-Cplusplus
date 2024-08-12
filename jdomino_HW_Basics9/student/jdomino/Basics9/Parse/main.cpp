//-----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

// Add functions and includes as needed

#include "Chunk.h"

int main(int argc, char *argv[])
{
	int rc = 0;
	bool nType = false;
	bool tType = false;

	Trace::out("ArgC: %d\n", argc);
	
	//Take in commands of argc count
	//commands start at argv[1]
	//argv[0] os the address of the exe
	for (int i = 1; i < argc; i++)
	{
		Trace::out("ArgV: %s\n", argv[i]);

		if (rc == -1)
		{
			break;
		}
		if (argc < 4 || argc == 5 || argc > 6)
		{
			//we're missing an argument, error
			rc = -1;
			break;
		}

		//Checking each type of argument one at a time
		if (strcmp(argv[i], "parse") == 0 || strcmp(argv[i], "Parse") == 0)
		{
			//Do nothing
		}
		//is it a -t command?
		else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0)
		{
			tType = true;
		}
		//is it a -n command?
		else if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "-N") == 0)
		{
			nType = true;
		}
		else if (tType)
		{
			int chunkCount = ChunkType::COUNT;
			bool foundEnum = false;

			for (int j = 0; j <= chunkCount; j++)
			{
				char* currChunk = "";


				//Only set new 
				if (!foundEnum)
				{
					if (j == 0)
					{
						currChunk = "VERTS_TYPE";
					}
					else if (j == 1)
					{
						currChunk = "NORMS_TYPE";
					}
					else if (j == 2)
					{
						currChunk = "ANIM_TYPE";
					}
					else if (j == 3)
					{
						currChunk = "TEXTURE_TYPE";
					}
					else if (j == 4)
					{
						currChunk = "UV_TYPE";
					}
				}


				if (strcmp(argv[i], currChunk) == 0 && !foundEnum)
				{
					rc = 0;

					//We have found our arg, clear the flag
					tType = false;
					foundEnum = true;
				}
				else if(j == chunkCount && !foundEnum)
				{
					rc = -1;
				}
				
			}
		}
		else if (nType)
		{
			//We're doing -n stuff
			//count the chars, max 19 or 20 including null
			Trace::out("Strlen of argv is : % d\n", strlen(argv[i]));

			size_t argvLen = strlen(argv[i]);
			if (argvLen < 20 && argvLen > 0)
			{
				rc = 0;
				nType = false;
			}
			else
			{
				rc = -1;
			}

		}
		else
		{
			rc = -1;
		}
		


	}

	return rc;
}

// ---  End of File ---------------
