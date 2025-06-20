bool checkInterval(unsigned long interval, unsigned long &previousMillis)
{
  // Mendapatkan waktu sekarang
  unsigned long currentMillis = millis();

  // Memeriksa apakah sudah melewati interval waktu yang ditentukan
  if (currentMillis - previousMillis >= interval)
  {
    // Menyimpan waktu terakhir
    previousMillis = currentMillis;

    return true;
  }

  return false;
}

void pembacaanRpm (){
    if (checkInterval(intervalRpm, milisRpm)) {
        rpmDepanKanan = encMdKananAVal * (60000 / intervalRpm) / perRotasi;
        rpmDepanKiri = encMdKiriAVal * (60000 / intervalRpm) / perRotasi;
        rpmBelakangKanan = encMbKananAVal * (60000 / intervalRpm) / perRotasi;
        rpmBelakangKiri = encMbKiriAVal * (60000 / intervalRpm) / perRotasi;

        encMdKananAVal = 0;
        encMdKiriAVal = 0;
        encMbKananAVal = 0;
        encMbKiriAVal = 0;
    }
}

void encMdKanan(){
  encMdKananAVal++;

  if ((digitalRead(encMdKananA) == HIGH) != (digitalRead(encMdKananB) == LOW))
  {
    encMdKananValJarak++;
  }
  else
  {
    encMdKananValJarak--;
  }
}

void encMdKiri(){
  encMdKiriAVal++;

  if ((digitalRead(encMdKiriA) == HIGH) != (digitalRead(encMdKiriB) == LOW))
  {
    encMdKiriValJarak++;
  }
  else
  {
    encMdKiriValJarak--;
  }
}

void encMbKanan(){
  encMdKananAVal++;

  if ((digitalRead(encMdKananA) == HIGH) != (digitalRead(encMdKananB) == LOW))
  {
    encMdKananValJarak++;
  }
  else
  {
    encMdKananValJarak--;
  }
}

void encMbKiri(){
  encMbKiriAVal++;

  if ((digitalRead(encMbKiriA) == HIGH) != (digitalRead(encMbKiriB) == LOW))
  {
    encMbKiriValJarak++;
  }
  else
  {
    encMbKiriValJarak--;
  }
}
