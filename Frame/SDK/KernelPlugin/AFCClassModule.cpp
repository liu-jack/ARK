/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2018 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#include "AFCClassModule.h"
#include "RapidXML/rapidxml.hpp"
#include "RapidXML/rapidxml_print.hpp"
#include "SDK/Core/Base/AFIData.h"
#include "SDK/Core/AFDataNode.h"

AFCClassModule::AFCClassModule(AFIPluginManager* p) : m_pElementModule(nullptr)
{
    pPluginManager = p;

    msConfigFileName = "DataConfig/Struct/LogicClass.xml";

    std::cout << "Using [" << pPluginManager->GetConfigPath() + msConfigFileName << "]" << std::endl;
}

AFCClassModule::~AFCClassModule()
{
    ClearAll();
}

bool AFCClassModule::Init()
{
    m_pElementModule = pPluginManager->FindModule<AFIElementModule>();

    bool bRet = Load();

    ARK_ASSERT_RET_VAL(bRet, false);

    return true;
}

bool AFCClassModule::Shut()
{
    bool bRet = ClearAll();
    ARK_ASSERT_RET_VAL(bRet, false);

    return true;
}

int AFCClassModule::ComputerType(const char* pstrTypeName, AFIData& var)
{
    if(0 == ARK_STRICMP(pstrTypeName, "bool"))
    {
        var.SetBool(NULL_BOOLEAN);
        return var.GetType();
    }
    if(0 == ARK_STRICMP(pstrTypeName, "int"))
    {
        var.SetInt(NULL_INT);
        return var.GetType();
    }
    if(0 == ARK_STRICMP(pstrTypeName, "int64"))
    {
        var.SetInt64(NULL_INT64);
        return var.GetType();
    }
    else if(0 == ARK_STRICMP(pstrTypeName, "float"))
    {
        var.SetFloat(NULL_FLOAT);
        return var.GetType();
    }
    else if(0 == ARK_STRICMP(pstrTypeName, "double"))
    {
        var.SetDouble(NULL_DOUBLE);
        return var.GetType();
    }
    else if(0 == ARK_STRICMP(pstrTypeName, "string"))
    {
        var.SetString(NULL_STR.c_str());
        return var.GetType();
    }
    else if(0 == ARK_STRICMP(pstrTypeName, "object"))
    {
        var.SetObject(NULL_GUID);
        return var.GetType();
    }

    return DT_UNKNOWN;
}

bool AFCClassModule::AddNodes(rapidxml::xml_node<>* pNodeRootNode, ARK_SHARE_PTR<AFIClass> pClass)
{
    for(rapidxml::xml_node<>* pNode = pNodeRootNode->first_node(); pNode != nullptr; pNode = pNode->next_sibling())
    {
        if(pNode == nullptr)
        {
            continue;
        }

        const char* strNodeName = pNode->first_attribute("Id")->value();
        if(pClass->GetNodeManager()->GetNode(strNodeName) != nullptr)
        {
            ARK_ASSERT(0, strNodeName, __FILE__, __FUNCTION__);
            continue;
        }

        const char* pstrType = pNode->first_attribute("Type")->value();
        bool bPublic = ARK_LEXICAL_CAST<bool>(pNode->first_attribute("Public")->value());
        bool bPrivate = ARK_LEXICAL_CAST<bool>(pNode->first_attribute("Private")->value());
        bool bSave = ARK_LEXICAL_CAST<bool>(pNode->first_attribute("Save")->value());
        bool bRealTime = ARK_LEXICAL_CAST<bool>(pNode->first_attribute("Cache")->value()); //TODO:real-time

        AFCData varNode;
        if(DT_UNKNOWN == ComputerType(pstrType, varNode))
        {
            ARK_ASSERT(0, strNodeName, __FILE__, __FUNCTION__);
        }

        int8_t feature(0);
        if(bPublic)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataNode::PF_PUBLIC);
        }

        if(bPrivate)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataNode::PF_PRIVATE);
        }

        if(bRealTime)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataNode::PF_REAL_TIME);
        }

        if(bSave)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataNode::PF_SAVE);
        }

        pClass->GetNodeManager()->AddNode(strNodeName, varNode, feature);
    }

    return true;
}

bool AFCClassModule::AddTables(rapidxml::xml_node<>* pTableRootNode, ARK_SHARE_PTR<AFIClass> pClass)
{
    for(rapidxml::xml_node<>* pTableNode = pTableRootNode->first_node(); pTableNode != nullptr;  pTableNode = pTableNode->next_sibling())
    {
        const char* pTableName = pTableNode->first_attribute("Id")->value();
        if(pClass->GetTableManager()->GetTable(pTableName) != nullptr)
        {
            ARK_ASSERT(0, pTableName, __FILE__, __FUNCTION__);
            continue;
        }

        //const char* pstrRow = pTableNode->first_attribute("Row")->value();
        //const char* pstrCol = pTableNode->first_attribute("Col")->value();

        bool bPublic = ARK_LEXICAL_CAST<bool>(pTableNode->first_attribute("Public")->value());
        bool bPrivate = ARK_LEXICAL_CAST<bool>(pTableNode->first_attribute("Private")->value());
        bool bSave = ARK_LEXICAL_CAST<bool>(pTableNode->first_attribute("Save")->value());
        bool bRealtime = ARK_LEXICAL_CAST<bool>(pTableNode->first_attribute("Cache")->value());//TODO:real-time

        AFCDataList col_type_list;
        for(rapidxml::xml_node<>* pTableColNode = pTableNode->first_node(); pTableColNode != nullptr;  pTableColNode = pTableColNode->next_sibling())
        {
            AFCData data;
            const char* pstrColType = pTableColNode->first_attribute("Type")->value();
            if(DT_UNKNOWN == ComputerType(pstrColType, data))
            {
                ARK_ASSERT(0, pTableName, __FILE__, __FUNCTION__);
            }

            col_type_list.Append(data);
        }

        int8_t feature(0);
        if(bPublic)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataTable::TABLE_PUBLIC);
        }

        if(bPrivate)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataTable::TABLE_PRIVATE);
        }

        if(bRealtime)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataTable::TABLE_REAL_TIME);
        }

        if(bSave)
        {
            BitValue<int8_t>::SetBitValue(feature, AFDataTable::TABLE_SAVE);
        }

        bool result = pClass->GetTableManager()->AddTable(NULL_GUID, pTableName, col_type_list, feature);
        ARK_ASSERT(result, "add table failed, please check", __FILE__, __FUNCTION__);
    }

    return true;
}

bool AFCClassModule::AddComponents(rapidxml::xml_node<>* pComponentRootNode, ARK_SHARE_PTR<AFIClass> pClass)
{
    //for(rapidxml::xml_node<>* pComponentNode = pComponentRootNode->first_node(); pComponentNode; pComponentNode = pComponentNode->next_sibling())
    //{
    //    if(pComponentNode)
    //    {
    //        const char* strComponentName = pComponentNode->first_attribute("Name")->value();
    //        const char* strLanguage = pComponentNode->first_attribute("Language")->value();
    //        const char* strEnable = pComponentNode->first_attribute("Enable")->value();
    //        bool bEnable = ARK_LEXICAL_CAST<bool>(strEnable);
    //        if(bEnable)
    //        {
    //            if(pClass->GetComponentManager()->GetElement(strComponentName))
    //            {
    //                //error
    //                ARK_ASSERT(0, strComponentName, __FILE__, __FUNCTION__);
    //                continue;
    //            }
    //            ARK_SHARE_PTR<AFIComponent> xComponent = std::make_shared<AFCComponent>(NULL_GUID, strComponentName);
    //            pClass->GetComponentManager()->AddComponent(strComponentName, xComponent);
    //        }
    //    }
    //}

    return true;
}

bool AFCClassModule::AddClassInclude(const char* pstrClassFilePath, ARK_SHARE_PTR<AFIClass> pClass)
{
    if(pClass->Find(pstrClassFilePath))
    {
        return false;
    }
    //////////////////////////////////////////////////////////////////////////
    std::string strFile = pPluginManager->GetConfigPath() + pstrClassFilePath;
    rapidxml::file<> fdoc(strFile.c_str());

    rapidxml::xml_document<> xDoc;
    xDoc.parse<0>(fdoc.data());
    //////////////////////////////////////////////////////////////////////////

    //support for unlimited layer class inherits
    rapidxml::xml_node<>* root = xDoc.first_node();

    rapidxml::xml_node<>* pRootNodeDataNode = root->first_node("DataNodes");
    if(pRootNodeDataNode != nullptr)
    {
        if(!AddNodes(pRootNodeDataNode, pClass))
        {
            ARK_ASSERT(0, "AddNodes failed", __FILE__, __FUNCTION__);
            return false;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    //Add table
    rapidxml::xml_node<>* pRootNodeDataTable = root->first_node("DataTables");
    if(pRootNodeDataTable != nullptr)
    {
        if(!AddTables(pRootNodeDataTable, pClass))
        {
            ARK_ASSERT(0, "AddTables failed", __FILE__, __FUNCTION__);
            return false;
        }
    }

    //rapidxml::xml_node<>* pComponentRootNode = root->first_node("Components");
    //if(pComponentRootNode)
    //{
    //    if(!AddComponents(pComponentRootNode, pClass))
    //    {
    //        ARK_ASSERT(0, "AddComponents failed", __FILE__, __FUNCTION__);
    //        return false;
    //    }
    //}

    //and include file
    rapidxml::xml_node<>* pIncludeRootNode = root->first_node("Includes");
    if(pIncludeRootNode)
    {
        for(rapidxml::xml_node<>* includeNode = pIncludeRootNode->first_node(); includeNode; includeNode = includeNode->next_sibling())
        {
            const char* pstrIncludeFile = includeNode->first_attribute("Id")->value();
            if(AddClassInclude(pstrIncludeFile, pClass))
            {
                pClass->Add(pstrIncludeFile);
            }
        }
    }

    return true;
}

bool AFCClassModule::AddClass(const char* pstrClassFilePath, ARK_SHARE_PTR<AFIClass> pClass)
{
    ARK_SHARE_PTR<AFIClass> pParent = pClass->GetParent();
    while(nullptr != pParent)
    {
        //inherited some properties form class of parent
        std::string strFileName;
        pParent->First(strFileName);
        while(!strFileName.empty())
        {
            if(pClass->Find(strFileName))
            {
                strFileName.clear();
                continue;
            }

            if(AddClassInclude(strFileName.c_str(), pClass))
            {
                pClass->Add(strFileName);
            }

            strFileName.clear();
            pParent->Next(strFileName);
        }

        pParent = pParent->GetParent();
    }

    //////////////////////////////////////////////////////////////////////////
    if(AddClassInclude(pstrClassFilePath, pClass))
    {
        pClass->Add(pstrClassFilePath);
    }

    //file.close();

    return true;
}

bool AFCClassModule::AddClass(const std::string& strClassName, const std::string& strParentName)
{
    ARK_SHARE_PTR<AFIClass> pParentClass = GetElement(strParentName);
    ARK_SHARE_PTR<AFIClass> pChildClass = GetElement(strClassName);
    if(nullptr == pChildClass)
    {
        pChildClass = std::make_shared<AFCClass>(strClassName);
        AddElement(strClassName, pChildClass);
        //pChildClass = CreateElement( strClassName );

        pChildClass->SetTypeName("");
        pChildClass->SetInstancePath("");

        if(pParentClass)
        {
            pChildClass->SetParent(pParentClass);
        }
    }

    return true;
}

bool AFCClassModule::Load(rapidxml::xml_node<>* attrNode, ARK_SHARE_PTR<AFIClass> pParentClass)
{
    const char* pstrLogicClassName = attrNode->first_attribute("Id")->value();
    const char* pstrType = attrNode->first_attribute("Type")->value();
    const char* pstrPath = attrNode->first_attribute("Path")->value();
    const char* pstrInstancePath = attrNode->first_attribute("ResPath")->value();

    //printf( "-----------------------------------------------------\n");
    //printf( "%s:\n", pstrLogicClassName );

    ARK_SHARE_PTR<AFIClass> pClass = std::make_shared<AFCClass>(pstrLogicClassName);
    AddElement(pstrLogicClassName, pClass);
    pClass->SetParent(pParentClass);
    pClass->SetTypeName(pstrType);
    pClass->SetInstancePath(pstrInstancePath);

    if(!AddClass(pstrPath, pClass))
    {
        return false;
    }

    for(rapidxml::xml_node<>* pDataNode = attrNode->first_node(); pDataNode; pDataNode = pDataNode->next_sibling())
    {
        //her children
        if(!Load(pDataNode, pClass))
        {
            return false;
        }
    }
    //printf( "-----------------------------------------------------\n");
    return true;
}

bool AFCClassModule::Load()
{
    std::string strFile = pPluginManager->GetConfigPath() + msConfigFileName;
    rapidxml::file<> fdoc(strFile.c_str());

    rapidxml::xml_document<> xDoc;
    xDoc.parse<0>(fdoc.data());
    //////////////////////////////////////////////////////////////////////////
    //support for unlimited layer class inherits
    rapidxml::xml_node<>* root = xDoc.first_node();
    for(rapidxml::xml_node<>* attrNode = root->first_node(); attrNode; attrNode = attrNode->next_sibling())
    {
        if(!Load(attrNode, NULL))
        {
            return false;
        }
    }
    return true;
}

bool AFCClassModule::Save()
{
    return true;
}

ARK_SHARE_PTR<AFIDataNodeManager> AFCClassModule::GetNodeManager(const std::string& strClassName)
{
    ARK_SHARE_PTR<AFIClass> pClass = GetElement(strClassName);
    if(nullptr != pClass)
    {
        return pClass->GetNodeManager();
    }

    return nullptr;
}

ARK_SHARE_PTR<AFIDataTableManager> AFCClassModule::GetTableManager(const std::string& strClassName)
{
    ARK_SHARE_PTR<AFIClass> pClass = GetElement(strClassName);
    if(nullptr != pClass)
    {
        return pClass->GetTableManager();
    }

    return NULL;
}

//ARK_SHARE_PTR<AFIComponentManager> AFCClassModule::GetClassComponentManager(const std::string& strClassName)
//{
//    ARK_SHARE_PTR<AFIClass> pClass = GetElement(strClassName);
//    if(nullptr != pClass)
//    {
//        return pClass->GetComponentManager();
//    }
//
//    return NULL;
//}

bool AFCClassModule::Clear()
{
    return true;
}

bool AFCClassModule::AddClassCallBack(const std::string& strClassName, const CLASS_EVENT_FUNCTOR_PTR& cb)
{
    ARK_SHARE_PTR<AFIClass> pClass = GetElement(strClassName);
    if(nullptr == pClass)
    {
        return false;
    }

    return pClass->AddClassCallBack(cb);
}

bool AFCClassModule::DoEvent(const AFGUID& objectID, const std::string& strClassName, const CLASS_OBJECT_EVENT eClassEvent, const AFIDataList& valueList)
{
    ARK_SHARE_PTR<AFIClass> pClass = GetElement(strClassName);
    if(nullptr == pClass)
    {
        return false;
    }

    return pClass->DoEvent(objectID, eClassEvent, valueList);
}