/*  =========================================================================
    fty_asset_dto - Asset DTO: defines ASSET attributes for data exchange

    Copyright (C) 2016 - 2020 Eaton

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    =========================================================================
*/

#pragma once

#include <map>
#include <string>

#include <fty_common.h>

#include <cxxtools/serializationinfo.h>
#include <cxxtools/jsondeserializer.h>

typedef struct _fty_proto_t fty_proto_t;

namespace fty
{
    /// List of valid asset statuses
    enum class AssetStatus
    {
        Unknown = 0,
        Active,
        Nonactive
    };

    // WARNING keep consistent with DB table t_bios_asset_element_type
    static constexpr const char *TYPE_UNKNOWN                         = "unknown";         // 0
    static constexpr const char *TYPE_GROUP                           = "group";           // 1
    static constexpr const char *TYPE_DATACENTER                      = "datacenter";      // 2
    static constexpr const char *TYPE_ROOM                            = "room";            // 3
    static constexpr const char *TYPE_ROW                             = "row" ;            // 4
    static constexpr const char *TYPE_RACK                            = "rack";            // 5
    static constexpr const char *TYPE_DEVICE                          = "device";          // 6
    static constexpr const char *TYPE_INFRA_SERVICE                   = "infra-service";   // 7
    static constexpr const char *TYPE_CLUSTER                         = "cluster";         // 8
    static constexpr const char *TYPE_HYPERVISOR                      = "hypervisor";      // 9
    static constexpr const char *TYPE_VIRTUAL_MACHINE                 = "virtual-machine"; // 10
    static constexpr const char *TYPE_STORAGE_SERVICE                 = "storage-service"; // 11
    static constexpr const char *TYPE_VAPP                            = "vapp";            // 12
    static constexpr const char *TYPE_CONNECTOR                       = "connector";       // 13
    static constexpr const char *TYPE_SERVER                          = "server";          // 15
    static constexpr const char *TYPE_PLANNER                         = "planner";         // 16
    static constexpr const char *TYPE_PLAN                            = "plan";            // 17

    // WARNING keep consistent with DB table t_bios_asset_device_type
    static constexpr const char *SUB_UNKNOWN                          = "unknown";                          // 0
    static constexpr const char *SUB_UPS                              = "ups";                              //1
    static constexpr const char *SUB_GENSET                           = "genset";                           //2
    static constexpr const char *SUB_EPDU                             = "epdu";                             //3
    static constexpr const char *SUB_PDU                              = "pdu";                              //4
    static constexpr const char *SUB_SERVER                           = "server";                           //5
    static constexpr const char *SUB_FEED                             = "feed";                             //6
    static constexpr const char *SUB_STS                              = "sts";                              //7
    static constexpr const char *SUB_SWITCH                           = "switch";                           //8
    static constexpr const char *SUB_STORAGE                          = "storage";                          //9
    static constexpr const char *SUB_VM                               = "vm";                               //10
    static constexpr const char *SUB_N_A                              = "N_A";                              //11
    static constexpr const char *SUB_ROUTER                           = "router";                           //12
    static constexpr const char *SUB_RACK_CONTROLLER                  = "rack controller";                  //13
    static constexpr const char *SUB_SENSOR                           = "sensor";                           //14
    static constexpr const char *SUB_APPLIANCE                        = "appliance";                        //15
    static constexpr const char *SUB_CHASSIS                          = "chassis";                          //16
    static constexpr const char *SUB_PATCH_PANEL                      = "patch panel";                      //17
    static constexpr const char *SUB_OTHER                            = "other";                            //18
    static constexpr const char *SUB_SENSORGPIO                       = "sensorgpio";                       //19
    static constexpr const char *SUB_GPO                              = "gpo";                              //20
    static constexpr const char *SUB_NETAPP_ONTAP_NODE                = "netapp.ontap.node";                //21
    static constexpr const char *SUB_IPMINFRA_SERVER                  = "ipminfra.server";                  //22
    static constexpr const char *SUB_IPMINFRA_SERVICE                 = "ipminfra.service";                 //23
    static constexpr const char *SUB_VMWARE_VCENTER                   = "vmware.vcenter";                   //24
    static constexpr const char *SUB_CITRIX_POOL                      = "citrix.pool";                      //25
    static constexpr const char *SUB_VMWARE_CLUSTER                   = "vmware.cluster";                   //26
    static constexpr const char *SUB_VMWARE_ESXI                      = "vmware.esxi";                      //27
    static constexpr const char *SUB_MICROSOFT_HYPERV                 = "microsoft.hyperv";                 //28
    static constexpr const char *SUB_VMWARE_VM                        = "vmware.vm";                        //29
    static constexpr const char *SUB_MICROSOFT_VM                     = "microsoft.vm";                     //30
    static constexpr const char *SUB_CITRIX_VM                        = "citrix.vm";                        //31
    static constexpr const char *SUB_NETAPP_NODE                      = "netapp.node";                      //32
    static constexpr const char *SUB_VMWARE_STANDALONE_ESXI           = "vmware.standalone.esxi";           //33
    static constexpr const char *SUB_VMWARE_TASK                      = "vmware.task";                      //34
    static constexpr const char *SUB_VMWARE_VAPP                      = "vmware.vapp";                      //35
    static constexpr const char *SUB_CITRIX_XENSERVER                 = "citrix.xenserver";                 //36
    static constexpr const char *SUB_CITRIX_VAPP                      = "citrix.vapp";                      //37
    static constexpr const char *SUB_CITRIX_TASK                      = "citrix.task";                      //38
    static constexpr const char *SUB_MICROSOFT_VIRTUALIZATION_MACHINE = "microsoft.virtualization.machine"; //39
    static constexpr const char *SUB_MICROSOFT_TASK                   = "microsoft.task";                   //40
    static constexpr const char *SUB_MICROSOFT_SERVER_CONNECTOR       = "microsoft.server.connector";       //41
    static constexpr const char *SUB_MICROSOFT_SERVER                 = "microsoft.server";                 //42
    static constexpr const char *SUB_MICROSOFT_CLUSTER                = "microsoft.cluster";                //43
    static constexpr const char *SUB_HP_ONEVIEW_CONNECTOR             = "hp.oneview.connector";             //44
    static constexpr const char *SUB_HP_ONEVIEW                       = "hp.oneview";                       //45
    static constexpr const char *SUB_HP_IT_SERVER                     = "hp.it.server";                     //46
    static constexpr const char *SUB_HP_IT_RACK                       = "hp.it.rack";                       //47
    static constexpr const char *SUB_NETAPP_SERVER                    = "netapp.server";                    //48
    static constexpr const char *SUB_NETAPP_ONTAP_CONNECTOR           = "netapp.ontap.connector";           //49
    static constexpr const char *SUB_NETAPP_ONTAP_CLUSTER             = "netapp.ontap.cluster";             //50
    static constexpr const char *SUB_NUTANIX_VM                       = "nutanix.vm";                       //51
    static constexpr const char *SUB_NUTANIX_PRISM_GATEWAY            = "nutanix.prism.gateway";            //52
    static constexpr const char *SUB_NUTANIX_NODE                     = "nutanix.node";                     //53
    static constexpr const char *SUB_NUTANIX_CLUSTER                  = "nutanix.cluster";                  //54
    static constexpr const char *SUB_NUTANIX_PRISM_CONNECTOR          = "nutanix.prism.connector";          //55
    static constexpr const char *SUB_VMWARE_VCENTER_CONNECTOR         = "vmware.vcenter.connector";         //60
    static constexpr const char *SUB_VMWARE_STANDALONE_ESXI_CONNECTOR = "vmware.standalone.esxi.connector"; //61
    static constexpr const char *SUB_NETAPP_ONTAP                     = "netapp.ontap";                     //62
    static constexpr const char *SUB_VMWARE_SRM                       = "vmware.srm";                       //65
    static constexpr const char *SUB_VMWARE_SRM_PLAN                  = "vmware.srm.plan";                  //66


    class Asset
    {
        public:
        using ExtMap = std::map<std::string, std::pair<std::string,bool>>;

        // getters
        const std::string       & getInternalName() const;
        AssetStatus               getAssetStatus() const;
        const std::string       & getAssetType() const;
        const std::string       & getAssetSubtype() const;
        const std::string       & getParentId() const;
        const std::string       & getExtEntry(const std::string & entryName) const;
        bool                      isExtEntryReadOnly(const std::string & entryName) const;
        int                       getPriority() const;
        const Asset::ExtMap    & getExt() const;

        // setters
        void setInternalName(const std::string & internalName);
        void setAssetStatus(AssetStatus assetStatus);
        void setAssetType(const std::string & assetType);
        void setAssetSubtype(const std::string & assetSubtype);
        void setParentId(const std::string & parendId);
        void setPriority(int priority);
        void setExtEntry(const std::string & entryName, const std::string & value, bool readOnly = false);
        void setExt(const Asset::ExtMap & map);

        // overload equality and inequality check
        bool operator== (const Asset &asset) const;
        bool operator!= (const Asset &asset) const;

        private:
        // internal name = <subtype>-<id>)
        std::string    m_internalName;

        AssetStatus    m_assetStatus   = AssetStatus::Unknown;
        std::string    m_assetType     = TYPE_UNKNOWN;
        std::string    m_assetSubtype  = SUB_UNKNOWN;

        // direct parent iname
        std::string    m_parentId;
        // priority 1..5 (1 is most, 5 is least)
        int            m_priority      = 5;

        // ext map storage (asset-specific values with readonly attribut)
        Asset::ExtMap m_ext;
    };

    void operator<<= (cxxtools::SerializationInfo & si, const Asset & asset);
    void operator>>= (const cxxtools::SerializationInfo & si, Asset & asset);

    fty_proto_t * assetToFtyProto(const Asset & asset, const std::string & operation);
    Asset ftyProtoToAsset(fty_proto_t * proto, bool extAttributReadOnly = false);
}

//  Self test of this class
void fty_asset_dto_test (bool verbose);

