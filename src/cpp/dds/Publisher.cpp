/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This copy of FastCdr is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/*
 * Publisher.cpp
 *
 *  Created on: Feb 27, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *              grcanosa@gmail.com  	
 */

#include "eprosimartps/Publisher.h"
#include "eprosimartps/RTPSWriter.h"
#include "eprosimartps/ReaderLocator.h"
#include "eprosimartps/StatelessWriter.h"

namespace eprosima {
namespace dds {

Publisher::Publisher(){

}

Publisher::Publisher(RTPSWriter* Win) {
	// TODO Auto-generated constructor stub
	W = Win;
}

Publisher::~Publisher() {
	// TODO Auto-generated destructor stub
}

bool Publisher::write(void* Data) {
	//Convert data to serialized Payload
	cout << "Writing New Data" << endl;
	SerializedPayload_t Payload;
	type.serialize(&Payload,Data);
	//create new change
	CacheChange_t change;
	if(!W->new_change(ALIVE,&Payload,Data,&change))
	{
		cout<< B_RED << "New Change creation failed"<< DEF << endl;
		return false;
	}
	if(!W->writer_cache.add_change(change))
	{
		cout << B_RED << "Add change failed" << DEF << endl;
		return false;
	}
	return true;
}

bool Publisher::removeMinSeqChange()
{
	W->writer_cache.historyMutex.lock();
	if(!W->writer_cache.changes.empty())
	{
		SequenceNumber_t sn;
		GUID_t gui;
		W->writer_cache.get_seq_num_min(&sn,&gui);
		W->writer_cache.remove_change(sn,gui);
		W->writer_cache.historyMutex.unlock();
			return true;
	}
	W->writer_cache.historyMutex.unlock();
	return false;
}

bool Publisher::removeAllChange()
{
	return W->writer_cache.removeAll();
}

int Publisher::getHistory_n()
{
	return W->writer_cache.changes.size();
}

bool Publisher::addReaderLocator(Locator_t Loc,bool expectsInlineQos)
{
	ReaderLocator RL;
	RL.expectsInlineQos = expectsInlineQos;
	RL.locator = Loc;
	cout << "Adding ReaderLocator at: "<< RL.locator.to_IP4_string()<<":"<<RL.locator.port<< endl;
	if(W->stateType==STATELESS)
		((StatelessWriter*)W)->reader_locator_add(RL);
	//TODOG add proxy
	return true;
}


} /* namespace dds */
} /* namespace eprosima */

