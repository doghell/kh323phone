//
// h4506.cxx
//
// Code automatically generated by asnparse.
//

#ifdef P_USE_PRAGMA
#pragma implementation "h4506.h"
#endif

#include <ptlib.h>
#include "h450/h4506.h"

#define new PNEW


#if ! H323_DISABLE_H4506



#ifndef PASN_NOPRINTON
const static PASN_Names Names_H4506_CallWaitingOperations[]={
        {"callWaiting",105}
};
#endif
//
// CallWaitingOperations
//

H4506_CallWaitingOperations::H4506_CallWaitingOperations(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Enumeration(tag, tagClass, 105, FALSE
#ifndef PASN_NOPRINTON
    ,(const PASN_Names *)Names_H4506_CallWaitingOperations,1
#endif
    )
{
}


H4506_CallWaitingOperations & H4506_CallWaitingOperations::operator=(unsigned v)
{
  SetValue(v);
  return *this;
}


PObject * H4506_CallWaitingOperations::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H4506_CallWaitingOperations::Class()), PInvalidCast);
#endif
  return new H4506_CallWaitingOperations(*this);
}


//
// ArrayOf_MixedExtension
//

H4506_ArrayOf_MixedExtension::H4506_ArrayOf_MixedExtension(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Array(tag, tagClass)
{
}


PASN_Object * H4506_ArrayOf_MixedExtension::CreateObject() const
{
  return new H4504_MixedExtension;
}


H4504_MixedExtension & H4506_ArrayOf_MixedExtension::operator[](PINDEX i) const
{
  return (H4504_MixedExtension &)array[i];
}


PObject * H4506_ArrayOf_MixedExtension::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H4506_ArrayOf_MixedExtension::Class()), PInvalidCast);
#endif
  return new H4506_ArrayOf_MixedExtension(*this);
}


//
// CallWaitingArg
//

H4506_CallWaitingArg::H4506_CallWaitingArg(unsigned tag, PASN_Object::TagClass tagClass)
  : PASN_Sequence(tag, tagClass, 2, TRUE, 0)
{
  m_nbOfAddWaitingCalls.SetConstraints(PASN_Object::FixedConstraint, 0, 255);
  m_extensionArg.SetConstraints(PASN_Object::FixedConstraint, 0, 255);
}


#ifndef PASN_NOPRINTON
void H4506_CallWaitingArg::PrintOn(ostream & strm) const
{
  int indent = strm.precision() + 2;
  strm << "{\n";
  if (HasOptionalField(e_nbOfAddWaitingCalls))
    strm << setw(indent+22) << "nbOfAddWaitingCalls = " << setprecision(indent) << m_nbOfAddWaitingCalls << '\n';
  if (HasOptionalField(e_extensionArg))
    strm << setw(indent+15) << "extensionArg = " << setprecision(indent) << m_extensionArg << '\n';
  strm << setw(indent-1) << setprecision(indent-2) << "}";
}
#endif


PObject::Comparison H4506_CallWaitingArg::Compare(const PObject & obj) const
{
#ifndef PASN_LEANANDMEAN
  PAssert(PIsDescendant(&obj, H4506_CallWaitingArg), PInvalidCast);
#endif
  const H4506_CallWaitingArg & other = (const H4506_CallWaitingArg &)obj;

  Comparison result;

  if ((result = m_nbOfAddWaitingCalls.Compare(other.m_nbOfAddWaitingCalls)) != EqualTo)
    return result;
  if ((result = m_extensionArg.Compare(other.m_extensionArg)) != EqualTo)
    return result;

  return PASN_Sequence::Compare(other);
}


PINDEX H4506_CallWaitingArg::GetDataLength() const
{
  PINDEX length = 0;
  if (HasOptionalField(e_nbOfAddWaitingCalls))
    length += m_nbOfAddWaitingCalls.GetObjectLength();
  if (HasOptionalField(e_extensionArg))
    length += m_extensionArg.GetObjectLength();
  return length;
}


BOOL H4506_CallWaitingArg::Decode(PASN_Stream & strm)
{
  if (!PreambleDecode(strm))
    return FALSE;

  if (HasOptionalField(e_nbOfAddWaitingCalls) && !m_nbOfAddWaitingCalls.Decode(strm))
    return FALSE;
  if (HasOptionalField(e_extensionArg) && !m_extensionArg.Decode(strm))
    return FALSE;

  return UnknownExtensionsDecode(strm);
}


void H4506_CallWaitingArg::Encode(PASN_Stream & strm) const
{
  PreambleEncode(strm);

  if (HasOptionalField(e_nbOfAddWaitingCalls))
    m_nbOfAddWaitingCalls.Encode(strm);
  if (HasOptionalField(e_extensionArg))
    m_extensionArg.Encode(strm);

  UnknownExtensionsEncode(strm);
}


PObject * H4506_CallWaitingArg::Clone() const
{
#ifndef PASN_LEANANDMEAN
  PAssert(IsClass(H4506_CallWaitingArg::Class()), PInvalidCast);
#endif
  return new H4506_CallWaitingArg(*this);
}


#endif // if ! H323_DISABLE_H4506


// End of h4506.cxx
