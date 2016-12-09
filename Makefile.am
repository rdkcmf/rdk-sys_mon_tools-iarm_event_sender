##########################################################################
# If not stated otherwise in this file or this component's Licenses.txt
# file the following copyright and licenses apply:
#
# Copyright 2016 RDK Management
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
##########################################################################
SUBDIRS =
DIST_SUBDIRS =

# the list of header files that belong to the library (to be installed later)
AM_CFLAGS = $(DBUS_CFLAGS) $(DIRECT_CFLAGS) $(FUSION_CFLAGS) $(GLIB_CFLAGS) \
	    -I=${includedir}/rdk/iarmbus \
	    -I=${includedir}/rdk/iarmmgrs/power \
	    -I=${includedir}/rdk/iarmmgrs/sysmgr \
	    -I=${includedir}/rdk/iarmmgrs-hal

bin_PROGRAMS = IARM_event_sender IARM_imgStatusIndicator

IARM_event_sender_SOURCES = IARM_event_sender.c
IARM_event_sender_LDADD = $(DIRECT_LIBS) $(FUSION_LIBS) $(GLIB_LIBS) -lIARMBus $(DBUS_LIBS)

IARM_imgStatusIndicator_SOURCES = IARM_imgStatusIndicator.c
IARM_imgStatusIndicator_LDADD = $(DIRECT_LIBS) $(FUSION_LIBS) $(GLIB_LIBS) -lIARMBus $(DBUS_LIBS)

## IPK generation Support
IARM_event_sender_IPK_OUTDIR = $(abs_top_builddir)/ipk
IARM_event_sender_IPK_STAGING_DIR=$(abs_top_builddir)/staging_dir
IARM_event_sender_IPK_TMP_DIR=$(IARM_event_sender_IPK_STAGING_DIR)/ipk

IARM_event_sender_CONTROL_FILES = control
IARM_event_sender_IPK_FILES  = debian-binary control.tar.gz data.tar.gz
IARM_event_sender_IPK_OUTPUT = iarm-event-sender.ipk

package_ipk:
	echo "Generating IPK Package"
	make install DESTDIR=$(IARM_event_sender_IPK_STAGING_DIR) prefix=/usr
	tar -czvf $(IARM_event_sender_IPK_OUTDIR)/data.tar.gz -C $(IARM_event_sender_IPK_STAGING_DIR) usr
	tar -czvf $(IARM_event_sender_IPK_OUTDIR)/control.tar.gz -C $(IARM_event_sender_IPK_OUTDIR) $(IARM_event_sender_CONTROL_FILES)
	cd  $(IARM_event_sender_IPK_OUTDIR) && ar cr $(IARM_event_sender_IPK_OUTPUT) $(IARM_event_sender_IPK_FILES) && cd -
