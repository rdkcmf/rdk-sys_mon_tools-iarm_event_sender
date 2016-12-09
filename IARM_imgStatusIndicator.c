/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libIBus.h"
#include "libIBusDaemon.h"
#include "sysMgr.h"
#include "libIARMCore.h"

int main(int argc,char *argv[])
{
	IARM_Result_t retCode = IARM_RESULT_SUCCESS;
	IARM_Bus_SYSMgr_EventData_t eventData;
	char dwldStatus;
	printf("IARM_imgStatusIndicator  Entering %d\r\n", getpid());
	if (argc != 2) 
	{
            printf("Usage: %s <Download Status> \n",argv[0]);
            return 1;
        }
	dwldStatus=atoi(argv[1]);
	switch(dwldStatus)
	{
		case IARM_BUS_SYSMGR_IMAGE_FWDNLD_UNINITIALIZED : printf("Sending IARM_BUS_SYSMGR_IMAGE_FWDNLD_UNINITIALIZED \r\n");
									break;
		case IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_INPROGRESS : printf("Sending IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_INPROGRESS \r\n");
                                                                        break;
		case IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_COMPLETE : printf("Sending IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_COMPLETE \r\n");
                                                                        break;
		case IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_FAILED : printf("Sending IARM_BUS_SYSMGR_IMAGE_FWDNLD_DOWNLOAD_FAILED \r\n");
                                                                        break;
		default :
			printf("Wrong Parameter send, Exiting %d \n",dwldStatus);
			return 1;
	}	
	IARM_Bus_Init("IARM_imgStatusIndicator");
	IARM_Bus_Connect();
	eventData.data.imageFWDNLD.status = dwldStatus;
        IARM_Bus_BroadcastEvent(IARM_BUS_SYSMGR_NAME,
			(IARM_EventId_t)IARM_BUS_SYSMGR_EVENT_IMAGE_DNLD,(void *)&eventData, sizeof(eventData));
		printf(">>>>> Generate IARM_BUS_SYSMGR_NAME EVENT : IARM_BUS_SYSMGR_EVENT_IMAGE_DNLD \r\n");
		

	IARM_Bus_Disconnect();
	IARM_Bus_Term();
	printf("IARM_imgStatusIndicator closing \r\n");
}
