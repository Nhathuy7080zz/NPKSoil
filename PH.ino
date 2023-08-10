void ph()
{
  Serial.println("DATA PH      ");
  /*Read value Temp1*/
  result1 = node1.readHoldingRegisters(0x0000, 2);
  // do something with data if read is successful
  if (result1 == node1.ku8MBSuccess)
  {
    data1[0] = node1.receive();
    Temp1 = float(data1[0]);
    Serial.print("pH ");
    float ph = Temp1 / 10;
    Temp1 = ph;
    Serial.print(ph);
    Serial.println("pH");
  }
  delay(500);

}
