// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_MULTIDEVICE_SETUP_MULTIDEVICE_SETUP_CLIENT_FACTORY_H_
#define CHROME_BROWSER_CHROMEOS_MULTIDEVICE_SETUP_MULTIDEVICE_SETUP_CLIENT_FACTORY_H_

#include "base/memory/singleton.h"
#include "components/keyed_service/content/browser_context_keyed_service_factory.h"

class Profile;

namespace chromeos {

namespace multidevice_setup {

class MultiDeviceSetupClient;

// Singleton that owns all MultiDeviceSetupClient instances and associates them
// with Profiles.
class MultiDeviceSetupClientFactory : public BrowserContextKeyedServiceFactory {
 public:
  static MultiDeviceSetupClient* GetForProfile(Profile* profile);

  static MultiDeviceSetupClientFactory* GetInstance();

 private:
  friend struct base::DefaultSingletonTraits<MultiDeviceSetupClientFactory>;

  MultiDeviceSetupClientFactory();
  ~MultiDeviceSetupClientFactory() override;

  // BrowserContextKeyedServiceFactory:
  KeyedService* BuildServiceInstanceFor(
      content::BrowserContext* context) const override;

  DISALLOW_COPY_AND_ASSIGN(MultiDeviceSetupClientFactory);
};

}  // namespace multidevice_setup

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_MULTIDEVICE_SETUP_MULTIDEVICE_SETUP_CLIENT_FACTORY_H_
